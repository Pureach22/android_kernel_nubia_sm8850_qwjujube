__int64 __fastcall sde_hw_sspp_setup_csc(__int64 result, _DWORD *a2, int a3)
{
  __int64 v5; // x8
  unsigned int v6; // w9
  unsigned __int64 v7; // x8
  unsigned int v8; // w1

  if ( result && a2 )
  {
    v5 = *(_QWORD *)(result + 56);
    v6 = *(_DWORD *)(*(_QWORD *)(v5 + 48) + 144LL);
    v7 = *(_QWORD *)(v5 + 32) & 0x20LL;
    if ( v7 )
      v8 = v6 + 4;
    else
      v8 = v6;
    return sde_hw_csc_setup(result, v8, a2, v7 >> 5, a3);
  }
  return result;
}
