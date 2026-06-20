__int64 __fastcall ce_ipa_get_resource(__int64 result, _QWORD *a2, _DWORD *a3, _QWORD *a4)
{
  int v5; // w8
  unsigned int *v6; // x9
  unsigned __int64 v9; // x8
  __int64 v10; // x10
  _DWORD *v11; // x22
  __int64 v12; // x9
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(result + 20);
  v13[0] = 0;
  if ( v5 )
  {
    v6 = *(unsigned int **)(result + 136);
    if ( *v6 )
    {
      v9 = 0;
      v10 = 4;
      do
      {
        ++v9;
        *(_DWORD *)(*((_QWORD *)v6 + 5) + v10) = *(_DWORD *)(*((_QWORD *)v6 + 5) + v10) & 0xFFFC0000 | 0x3C;
        v10 += 8;
        v6 = *(unsigned int **)(result + 136);
      }
      while ( v9 < *v6 );
    }
    v11 = (_DWORD *)result;
    result = hif_read_phy_mem_base(*(_QWORD *)result, v13);
    *a2 = *(_QWORD *)(*(_QWORD *)v11 + 3936LL);
    *a3 = 8 * **((_DWORD **)v11 + 17);
    *a4 = v13[0]
        + (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)v11 + 624LL) + 256LL)
                       + (*(_DWORD *)(*(_QWORD *)(*(_QWORD *)v11 + 624LL) + 260LL)
                        - *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v11 + 624LL) + 256LL))
                       * v11[2]
                       + *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v11 + 616LL) + 352LL));
  }
  else
  {
    if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)result + 576LL) + 608LL) )
      v12 = 8;
    else
      v12 = 0;
    *(_QWORD *)(*(_QWORD *)(*(_QWORD *)result + 3936LL) + v12) = 0;
    *a3 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
