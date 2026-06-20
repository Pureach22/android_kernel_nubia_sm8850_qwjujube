__int64 __fastcall globals_show(__int64 a1)
{
  __int64 v1; // x8
  _QWORD *v2; // x21
  _QWORD *i; // x22

  _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(a1 + 128);
  v2 = *(_QWORD **)(v1 + 13112);
  for ( i = (_QWORD *)(v1 + 13112); v2 != i; v2 = (_QWORD *)*v2 )
    seq_printf(a1, "0x%pK-0x%pK %16llu %5s %s\n");
  _ReadStatusReg(SP_EL0);
  return 0;
}
