// Do it with #define -> checking buy #ifndef and other directive
#include <stdio.h>
#include "windows.h"

int main() {
    // init structs
    IMAGE_DOS_HEADER header_dos = {0};
    IMAGE_NT_HEADERS header_pe = {0};

    FILE *file_input_stream = fopen("C:\\InnerDesktop\\ITMO-All\\Embedded-Systems\\Laba-1\\test_winSCP.exe", "rb");
    FILE *file_output_stream_txt = fopen("C:\\InnerDesktop\\ITMO-All\\Embedded-Systems\\Laba-1\\results_sections.txt", "w");
    FILE *file_output_stream_code = fopen("C:\\InnerDesktop\\ITMO-All\\Embedded-Systems\\Laba-1\\only_code.txt", "wb");

    // read headers to dos header
    // https://habr.com/ru/post/266831/
    // https://firststeps.ru/mfc/winapi/r.php?23 <- nice link to understand how to work with IMAGE_DOS_HEADER
    fread(&header_dos, sizeof header_dos, 1, file_input_stream);

    // go to e._lfanew in header_dos
    fseek(file_input_stream, header_dos.e_lfanew, 0);
    // read PE_HEADER (NT)
    fread(&header_pe, sizeof header_pe, 1, file_input_stream);

    printf("You can find signature of PE-file on 0x%lx\n", header_dos.e_lfanew);
    printf("Signature: 0x%lx \n", header_pe.Signature);
    fprintf(file_output_stream_txt, "You can find signature of PE-file on 0x%lx\n", header_dos.e_lfanew);
    fprintf(file_output_stream_txt, "Signature: 0x%lx \n", header_pe.Signature);

    // read and output information about sections, file
    IMAGE_FILE_HEADER header_NT_file_header = header_pe.FileHeader;

    printf("Time from 16:00 31 December 1969 = %lu seconds\n", header_NT_file_header.TimeDateStamp);
    fprintf(file_output_stream_txt, "Time from 16:00 31 December 1969 = %lu seconds\n", header_NT_file_header.TimeDateStamp);
    printf("Number of sections: %d\n", header_NT_file_header.NumberOfSections);
    fprintf(file_output_stream_txt, "Number of sections: %d\n", header_NT_file_header.NumberOfSections);

    // printing entry point of code
    printf("Entry point address: 0x%08lu\n", header_pe.OptionalHeader.AddressOfEntryPoint);
    fprintf(file_output_stream_txt, "Entry point address: 0x%08lu\n\n", header_pe.OptionalHeader.AddressOfEntryPoint);

    // reading all sections
    IMAGE_SECTION_HEADER *current_section = malloc(IMAGE_SIZEOF_SECTION_HEADER * header_NT_file_header.NumberOfSections);
    for (int i = 0; i < header_NT_file_header.NumberOfSections; i++) {
        // we needn't use fseek here
        fread(&(current_section[i]), sizeof(IMAGE_SECTION_HEADER), 1, file_input_stream);

        fprintf(file_output_stream_txt, "№%02d Name -> %s \n\tVirtual size: 0x%08lx\n\n", i + 1, current_section[i].Name, current_section[i].Misc.VirtualSize);
        fprintf(file_output_stream_txt, "%s 0x%08lx\n", "VirtualAddress:\t\t", current_section[i].VirtualAddress);
        fprintf(file_output_stream_txt, "%2s 0x%08lx\n", "Raw data offset:\t", current_section[i].PointerToRawData);
        fprintf(file_output_stream_txt, "%2s 0x%08lx\n", "Size of raw data:\t", current_section[i].SizeOfRawData);
        fprintf(file_output_stream_txt, "%2s 0x%08lx\n", "Relocation offset:\t", current_section[i].PointerToRelocations);
        fprintf(file_output_stream_txt, "%2s 0x%08x\n", "Relocations number:\t", current_section[i].NumberOfRelocations);
        fprintf(file_output_stream_txt, "%2s 0x%08lx\n", "Line offset:\t\t", current_section[i].PointerToLinenumbers);
        fprintf(file_output_stream_txt, "%2s 0x%08x\n", "Lines number:\t\t", current_section[i].NumberOfLinenumbers);
        fprintf(file_output_stream_txt, "%2s 0x%08lx\n\n", "Characteristics:\t", current_section[i].Characteristics);
    }

    // checking all sections to program flag
    char* section_with_code;
    for (int i = 0; i < header_NT_file_header.NumberOfSections; i++) {
        // 0x20 <- needed flag
        if (!(current_section[i].Characteristics & 0x20)) {
            continue;
        }

        size_t pointer = current_section[i].PointerToRawData;
        fseek(file_input_stream, pointer, 0);
        section_with_code = malloc(current_section[i].SizeOfRawData);

        fread(section_with_code, current_section[i].SizeOfRawData, 1, file_input_stream);
        fwrite(section_with_code, current_section[i].SizeOfRawData, 1, file_output_stream_code);

        free(section_with_code);
    }

    return 0;
}
