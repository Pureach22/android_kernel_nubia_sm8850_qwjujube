__int64 __fastcall cam_reserve_icp_fw(__int64 a1, __int64 a2)
{
  __int64 v4; // x4
  __int64 v5; // x0
  unsigned int v6; // w21
  __int64 v7; // x0
  int v8; // w8
  __int64 v9; // x2
  __int64 v10; // x0
  __int64 v11; // x6
  const char *v12; // x5
  __int64 v13; // x4
  __int64 result; // x0
  _QWORD v15[12]; // [xsp+8h] [xbp-B8h] BYREF
  _QWORD v16[11]; // [xsp+68h] [xbp-58h] BYREF

  v16[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)(a1 + 16);
  v5 = *(_QWORD *)(*(_QWORD *)a1 + 744LL);
  memset(v15, 0, sizeof(v15));
  memset(v16, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v5, "memory-region", 0, 0, v4, v16) || !v16[0] )
  {
    v11 = *(unsigned int *)(a1 + 16);
    v12 = "FW memory carveout of ICP%d not found";
    v13 = 223;
  }
  else
  {
    v6 = of_address_to_resource(v16[0], 0, v15);
    if ( (v6 & 0x80000000) != 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_reserve_icp_fw",
        230,
        "Unable to get start of FW mem carveout of ICP%u",
        *(_DWORD *)(a1 + 16));
      goto LABEL_12;
    }
    v7 = v15[0];
    v8 = arm64_use_ng_mappings;
    *(_QWORD *)(a1 + 24) = v15[0];
    if ( v8 )
      v9 = 0x68000000000F0BLL;
    else
      v9 = 0x6800000000070BLL;
    v10 = ioremap_prot(v7, a2, v9);
    *(_QWORD *)(a1 + 8) = v10;
    if ( v10 )
    {
      _memset_io(v10, 0, a2);
LABEL_12:
      result = v6;
      goto LABEL_13;
    }
    v11 = *(unsigned int *)(a1 + 16);
    v12 = "Failed to map the FW of ICP%d";
    v13 = 237;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    64,
    1,
    "cam_reserve_icp_fw",
    v13,
    v12,
    v11);
  result = 4294967284LL;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
