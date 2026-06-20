__int64 __fastcall commit_icc_freq(__int64 *a1, _DWORD *a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  unsigned int v6; // w19

  result = icc_set_bw(
             *(_QWORD *)a1[15],
             (unsigned int)(a2[1] * *(_DWORD *)(a1[2] + 124)),
             (unsigned int)(*(_DWORD *)(a1[2] + 124) * *a2));
  if ( (result & 0x80000000) != 0 )
  {
    v5 = *a1;
    v6 = result;
    dev_err(v5, "icc set bw request failed: %d\n", result);
    return v6;
  }
  else
  {
    *((_DWORD *)a1 + 6) = *a2;
    *((_DWORD *)a1 + 7) = a2[1];
  }
  return result;
}
