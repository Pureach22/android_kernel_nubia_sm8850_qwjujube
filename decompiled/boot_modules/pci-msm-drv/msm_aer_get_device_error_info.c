__int64 __fastcall msm_aer_get_device_error_info(__int64 a1, _DWORD *a2)
{
  __int16 v2; // w24
  int v3; // w22
  _DWORD *v4; // x21
  int ext_capability; // w23
  __int64 result; // x0
  __int16 v9; // w10
  unsigned int v10; // w8
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_WORD *)(a1 + 114);
  v3 = *(unsigned __int16 *)(a1 + 74);
  a2[14] = 0;
  v4 = a2 + 14;
  a2[13] &= ~0x80000000;
  if ( !v3 )
    goto LABEL_8;
  v11 = 0;
  ext_capability = (unsigned __int16)pci_find_ext_capability(a1, 30);
  if ( !ext_capability )
  {
    if ( *(_QWORD *)a2 )
    {
      ipc_log_string(
        *(_QWORD *)(*(_QWORD *)a2 + 1704LL),
        "DBG1:%s: PCIe: RC%d: Could not read l1ss cap reg offset\n",
        "msm_aer_get_device_error_info",
        *(_DWORD *)(*(_QWORD *)a2 + 1348LL));
      ipc_log_string(
        *(_QWORD *)(*(_QWORD *)a2 + 1696LL),
        "%s: PCIe: RC%d: Could not read l1ss cap reg offset\n",
        "msm_aer_get_device_error_info",
        *(_DWORD *)(*(_QWORD *)a2 + 1348LL));
    }
    goto LABEL_8;
  }
  if ( (*((_WORD *)a2 + 27) & 3) == 2 )
  {
    pci_read_config_dword(a1, (unsigned int)(v3 + 16), v4);
    pci_read_config_dword(a1, (unsigned int)(v3 + 20), a2 + 15);
    pci_read_config_dword(a1, (unsigned int)(ext_capability + 8), a2 + 20);
    pcie_capability_read_word(a1, 18, a2 + 21);
    if ( (a2[14] & ~a2[15]) == 0 )
      goto LABEL_8;
LABEL_15:
    result = 1;
    goto LABEL_16;
  }
  if ( (v2 & 0xD0) != 0x40 && (v2 & 0xF0) != 0xA0 && (*((_WORD *)a2 + 27) & 3) != 0 )
    goto LABEL_15;
  pci_read_config_dword(a1, (unsigned int)(v3 + 4), v4);
  pci_read_config_dword(a1, (unsigned int)(v3 + 8), a2 + 15);
  pci_read_config_dword(a1, (unsigned int)(ext_capability + 8), a2 + 20);
  pcie_capability_read_word(a1, 18, a2 + 21);
  if ( (a2[14] & ~a2[15]) != 0 )
  {
    pci_read_config_dword(a1, (unsigned int)(v3 + 24), &v11);
    v9 = *(_WORD *)((char *)a2 + 57);
    v10 = a2[13] & 0xE0FFFFFF | ((v11 & 0x1F) << 24);
    a2[13] = v10;
    if ( (v9 & 0x1D90) != 0 )
    {
      a2[13] = v10 | 0x80000000;
      pci_read_config_dword(a1, (unsigned int)(v3 + 28), a2 + 16);
      pci_read_config_dword(a1, (unsigned int)(v3 + 32), a2 + 17);
      pci_read_config_dword(a1, (unsigned int)(v3 + 36), a2 + 18);
      pci_read_config_dword(a1, (unsigned int)(v3 + 40), a2 + 19);
    }
    goto LABEL_15;
  }
LABEL_8:
  result = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
