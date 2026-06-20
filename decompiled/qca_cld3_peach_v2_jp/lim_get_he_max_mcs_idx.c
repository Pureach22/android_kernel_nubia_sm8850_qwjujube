__int64 __fastcall lim_get_he_max_mcs_idx(int a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 result; // x0
  int v6; // [xsp+8h] [xbp-18h] BYREF
  __int16 v7; // [xsp+Ch] [xbp-14h] BYREF
  int v8; // [xsp+10h] [xbp-10h] BYREF
  __int16 v9; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v8 = 0;
  v7 = 0;
  v6 = 0;
  qdf_mem_set(&v8, 6u, 0);
  qdf_mem_set(&v6, 6u, 0);
  qdf_mem_copy(&v8, (const void *)(a2 + 20), 2u);
  qdf_mem_copy(&v6, (const void *)(a2 + 22), 2u);
  v4 = *(_QWORD *)(a2 + 1);
  if ( (v4 & 0x10000000000000LL) != 0 )
  {
    qdf_mem_copy((char *)&v8 + 2, (const void *)(a2 + 24), 2u);
    qdf_mem_copy((char *)&v6 + 2, (const void *)(a2 + 26), 2u);
    v4 = *(_QWORD *)(a2 + 1);
  }
  if ( (v4 & 0x20000000000000LL) != 0 )
  {
    qdf_mem_copy(&v9, (const void *)(a2 + 28), 2u);
    qdf_mem_copy(&v7, (const void *)(a2 + 30), 2u);
  }
  result = mlme_get_max_he_mcs_idx(a1, &v8, &v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
