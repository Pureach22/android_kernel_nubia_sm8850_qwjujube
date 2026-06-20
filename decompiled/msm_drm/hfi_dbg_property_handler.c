__int64 __fastcall hfi_dbg_property_handler(__int64 a1, int a2, int *a3, int a4)
{
  int v4; // w20
  __int64 result; // x0
  unsigned int v6; // w9
  int v7; // w20
  unsigned int v8; // w9
  void *v9; // x0
  const char *v10; // x1
  int *v11; // [xsp+8h] [xbp-28h] BYREF
  __int64 v12; // [xsp+10h] [xbp-20h] BYREF
  _QWORD v13[3]; // [xsp+18h] [xbp-18h] BYREF

  v13[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !hfi_dbg )
  {
    v9 = &unk_2348DE;
    v10 = "hfi_dbg_property_handler";
LABEL_23:
    result = printk(v9, v10);
    goto LABEL_24;
  }
  if ( a2 != -16777207 )
  {
    v9 = &unk_24F975;
    v10 = "hfi_dbg_property_handler";
    goto LABEL_23;
  }
  if ( !a3 )
  {
    v9 = &unk_231519;
    v10 = "hfi_dbg_property_handler";
    goto LABEL_23;
  }
  v4 = *a3;
  v13[0] = 0;
  v13[1] = 0;
  v11 = nullptr;
  v12 = 0;
  result = hfi_util_kv_parser_init(v13, a4 - 4, (__int64)(a3 + 1));
  if ( (_DWORD)result )
  {
    v9 = &unk_26FD2F;
    v10 = "hfi_dbg_parse_payload";
    goto LABEL_23;
  }
  if ( !v4 )
    goto LABEL_24;
  result = hfi_util_kv_parser_get_next((__int64)v13, 0, (_DWORD *)&v12 + 1, &v11, &v12);
  if ( (_DWORD)result )
  {
LABEL_19:
    v9 = &unk_21582F;
    v10 = "hfi_dbg_parse_payload";
    goto LABEL_23;
  }
  if ( !hfi_dbg )
  {
LABEL_20:
    printk(&unk_26C2D0, "_hfi_dbg_read_prop");
LABEL_22:
    v9 = &unk_27D0F1;
    v10 = "hfi_dbg_parse_payload";
    goto LABEL_23;
  }
  v6 = (HIDWORD(v12) & 0xFFFFF) - 327681;
  if ( v6 > 3 )
  {
LABEL_21:
    printk(&unk_22074E, "_hfi_dbg_read_prop");
    goto LABEL_22;
  }
  v7 = v4 - 1;
  for ( *(int *)((char *)(&off_29D380)[v6] + hfi_dbg) = *v11; v7; *(int *)((char *)(&off_29D380)[v8] + hfi_dbg) = *v11 )
  {
    result = hfi_util_kv_parser_get_next((__int64)v13, 1, (_DWORD *)&v12 + 1, &v11, &v12);
    if ( (_DWORD)result )
      goto LABEL_19;
    if ( !hfi_dbg )
      goto LABEL_20;
    v8 = (HIDWORD(v12) & 0xFFFFF) - 327681;
    if ( v8 >= 4 )
      goto LABEL_21;
    --v7;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
