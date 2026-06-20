__int64 __fastcall sde_spr_read_opr_value(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  int v5; // w8

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      v5 = sde_reg_read(a1, (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 416LL) + 120));
      *a2 = v5;
      return 0;
    }
  }
  return result;
}
