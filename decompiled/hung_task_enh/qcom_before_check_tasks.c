void __fastcall qcom_before_check_tasks(__int64 a1, __int64 a2, __int64 a3, _BYTE *a4)
{
  _BYTE *v4; // x8
  int v5; // w8
  __int64 v6; // x8

  v4 = (_BYTE *)(a2 + 5184);
  if ( (_UNKNOWN *)a2 == &init_task )
    v4 = &vendor_data_pad;
  if ( dword_65C4 == 1 )
  {
    if ( v4[361] != 2 )
      goto LABEL_6;
LABEL_9:
    *a4 = 0;
    return;
  }
  if ( !dword_65C4 && v4[361] != 1 )
    goto LABEL_9;
LABEL_6:
  *a4 = 1;
  if ( (*(_WORD *)(a2 + 1728) & 8) != 0 )
  {
    v5 = *(_DWORD *)(a2 + 48);
    if ( v5 == 2 || v5 == 260 || v5 == 8 )
    {
      v6 = *(_QWORD *)(a2 + 2352);
      if ( v6 && v6 + 250 * a3 - jiffies < 0 && *(_QWORD *)(a2 + 1672) && *(_QWORD *)(a2 + 1864) == a2 )
        ++dword_65C8;
    }
  }
}
