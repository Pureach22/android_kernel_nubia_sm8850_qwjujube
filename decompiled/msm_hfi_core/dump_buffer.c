__int64 __fastcall dump_buffer(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  __int64 v8; // x9
  __int64 result; // x0
  __int64 v10; // x3
  const char *v11; // x4
  unsigned int v12; // w21
  _QWORD v14[4]; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v15[2]; // [xsp+28h] [xbp-28h] BYREF
  _DWORD *v16; // [xsp+38h] [xbp-18h] BYREF
  __int64 v17; // [xsp+40h] [xbp-10h]
  __int64 v18; // [xsp+48h] [xbp-8h]

  v6 = v5;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v15[0] = 0;
  v15[1] = 0;
  memset(v14, 0, sizeof(v14));
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_19:
      result = printk(&unk_1905C, "dump_buffer", 1130, v6);
      goto LABEL_17;
    }
  }
  else
  {
    printk(&unk_1E83A, "dump_buffer", 1127, a4);
    if ( !a1 )
      goto LABEL_19;
  }
  if ( !a2 )
    goto LABEL_19;
  v8 = a2[2];
  v16 = (_DWORD *)*a2;
  LODWORD(v17) = v8;
  result = hfi_unpacker_get_header_info(&v16, v15, a3, a4, a5);
  if ( (_DWORD)result )
  {
    result = printk(&unk_193A6, "dump_buffer", 1140, v6);
  }
  else
  {
    v10 = LODWORD(v15[0]);
    if ( LODWORD(v15[0]) )
    {
      if ( (unsigned int)(HIDWORD(v15[0]) - 1) > 4 )
        v11 = "Unknown";
      else
        v11 = off_205A8[HIDWORD(v15[0]) - 1];
      if ( (~msm_hfi_core_debug_level & 0x10001) != 0
        || (result = printk(&unk_1DABF, "print_hfi_header_info", 412, LODWORD(v15[0])), LODWORD(v15[0])) )
      {
        v12 = 1;
        while ( !(unsigned int)hfi_unpacker_get_packet_info(&v16, v12, (__int64)v14, v10, (unsigned __int64)v11) )
        {
          result = print_hfi_packet_info(v14);
          if ( ++v12 > LODWORD(v15[0]) )
            goto LABEL_15;
        }
        result = printk(&unk_1BDAD, "dump_buffer", 1157, v6);
      }
      else
      {
LABEL_15:
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          result = printk(&unk_1C28B, "dump_buffer", 1163, v10);
      }
    }
    else if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    {
      result = printk(&unk_1C5C0, "dump_buffer", 1146, *a2);
    }
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
