#include <linux/efi.h>
#include <linux/types.h>

#include "efistub.h"

efi_status_t efi_pe_entry(efi_handle_t handle, efi_system_table_t *systab)
{	
	efi_loaded_image_t *image;
	efi_status_t status;
	unsigned long image_addr;
	unsigned long image_size = 0;
	/* addr/point and size pairs for memory management*/
	char *cmdline_ptr = NULL;
	efi_guid_t loaded_image_proto = LOADED_IMAGE_PROTOCOL_GUID;
	unsigned long reserve_addr = 0;
	unsigned long reserve_size = 0;
}