__int64 __fastcall chan_gate_enable_show(__int64 a1, __int64 a2, _WORD *a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  v5[0] = *(unsigned int *)(v3 + 1164);
  if ( LODWORD(v5[0]) )
  {
    result = (int)bitmap_print_to_pagebuf(1, a3, v5, *(unsigned int *)(v3 + 64));
  }
  else
  {
    result = 1;
    *a3 = 10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
