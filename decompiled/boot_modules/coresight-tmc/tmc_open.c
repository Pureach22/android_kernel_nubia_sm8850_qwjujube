__int64 __fastcall tmc_open(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  int v5; // w8
  __int64 v6; // x0
  __int64 result; // x0

  v2 = *(_QWORD *)(a2 + 32);
  v5 = *(_DWORD *)(v2 + 116);
  v6 = v2 - 24;
  switch ( v5 )
  {
    case 2:
      goto LABEL_4;
    case 1:
      result = tmc_read_prepare_etr(v6);
      if ( (_DWORD)result )
        return result;
      goto LABEL_7;
    case 0:
LABEL_4:
      result = tmc_read_prepare_etb(v6);
      if ( (_DWORD)result )
        return result;
LABEL_7:
      nonseekable_open(a1, a2);
      return 0;
  }
  return 4294967274LL;
}
