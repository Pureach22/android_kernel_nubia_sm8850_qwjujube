__int64 __fastcall msm_find_device_iter(__int64 a1, __int64 a2)
{
  int v4; // w8
  int v5; // w21
  __int64 v6; // x9
  int v7; // w8
  int v8; // w22
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x8
  char v12; // w9
  __int64 result; // x0
  __int16 v14; // [xsp+Ch] [xbp-14h] BYREF
  int v15; // [xsp+10h] [xbp-10h] BYREF
  int v16; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 52);
  v5 = *(unsigned __int16 *)(a1 + 74);
  if ( (v4 & 0xFF00) != 0 )
  {
    v6 = *(_QWORD *)(a1 + 16);
    if ( (*(_WORD *)(v6 + 306) & 4) == 0 )
    {
      if ( (unsigned __int16)*(_DWORD *)(a2 + 52) == (*(_DWORD *)(a1 + 56) | (*(unsigned __int8 *)(v6 + 248) << 8)) )
        goto LABEL_15;
      if ( (v4 & 0x800000) == 0 )
        goto LABEL_19;
    }
  }
  if ( !*(_DWORD *)(a1 + 2856) )
    goto LABEL_19;
  v16 = 0;
  v15 = 0;
  v14 = 0;
  pcie_capability_read_word(a1, 8, &v14);
  if ( (v14 & 0xF) == 0 || !v5 )
    goto LABEL_19;
  v7 = (*(_DWORD *)(a2 + 52) & 0x30000) == 0x20000 ? 16 : 4;
  v8 = (*(_DWORD *)(a2 + 52) & 0x30000) == 0x20000 ? 20 : 8;
  pci_read_config_dword(a1, (unsigned int)(v7 + v5), &v16);
  pci_read_config_dword(a1, (unsigned int)(v8 + v5), &v15);
  if ( (v16 & ~v15) == 0 )
    goto LABEL_19;
LABEL_15:
  if ( *(int *)(a2 + 48) > 4 )
  {
LABEL_18:
    result = 1;
LABEL_20:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v9 = pci_dev_get(a1);
  v11 = *(unsigned int *)(a2 + 48);
  if ( (unsigned int)v11 < 5 )
  {
    *(_QWORD *)(a2 + 8 * v11 + 8) = v9;
    v12 = *(_BYTE *)(a2 + 54);
    ++*(_DWORD *)(a2 + 48);
    if ( (v12 & 0x80) == 0 )
      goto LABEL_18;
LABEL_19:
    result = 0;
    goto LABEL_20;
  }
  __break(0x5512u);
  return msm_aer_get_device_error_info(v9, v10);
}
