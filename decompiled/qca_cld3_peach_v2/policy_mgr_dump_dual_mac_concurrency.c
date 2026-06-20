__int64 __fastcall policy_mgr_dump_dual_mac_concurrency(_QWORD *a1, const char *a2)
{
  char *v2; // x22
  _QWORD *v3; // x20
  unsigned __int64 v4; // x0
  __int64 v5; // x25
  unsigned __int64 v6; // x26
  unsigned int v7; // w28
  __int64 v8; // x19
  char *v9; // x21
  __int64 v10; // x27
  int v11; // w9
  const char *v12; // x5
  int v13; // w23
  int v14; // w20
  size_t v15; // x2
  __int64 v16; // x20
  __int64 i; // x19
  char *v18; // x20
  size_t v19; // x2
  __int64 v20; // x20
  __int64 result; // x0
  __int64 v22; // [xsp+0h] [xbp-40h]
  _QWORD *v23; // [xsp+8h] [xbp-38h]
  char src[8]; // [xsp+18h] [xbp-28h] BYREF
  __int64 v26; // [xsp+20h] [xbp-20h]
  __int64 v27; // [xsp+28h] [xbp-18h]
  __int16 v28; // [xsp+30h] [xbp-10h]
  __int64 v29; // [xsp+38h] [xbp-8h]

  v3 = a1;
  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v26 = 0;
  v27 = 0;
  *(_QWORD *)src = 0;
  v4 = qdf_mutex_acquire((__int64)(a1 + 7));
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 4;
  v23 = v3;
  do
  {
    v22 = v5;
    if ( v6 <= 3 )
    {
      v9 = (char *)&pm_conc_connection_list + 36 * v6;
      if ( (v9[28] & 1) != 0 )
      {
        v10 = v8;
        while ( (unsigned __int64)(v5 - 116) >= 0xFFFFFFFFFFFFFF4CLL )
        {
          v2 = (char *)&pm_conc_connection_list + v5;
          if ( *((_BYTE *)&pm_conc_connection_list + v5 + 64) == 1 )
          {
            if ( (unsigned __int64)(v5 - 140) < 0xFFFFFFFFFFFFFF4CLL )
              break;
            v4 = policy_mgr_are_2_freq_on_same_mac(*v3);
            if ( (v4 & 1) != 0 )
            {
              v4 = (unsigned __int64)qdf_mem_set(src, 0x1Au, 0);
              if ( (unsigned __int64)(v5 - 120) < 0xFFFFFFFFFFFFFF4CLL
                || (unsigned __int64)(v5 - 140) < 0xFFFFFFFFFFFFFF4CLL )
              {
                break;
              }
              v11 = *((_DWORD *)v2 + 10);
              v2 = (char *)&pm_conc_connection_list + v5;
              v12 = *((_DWORD *)v9 + 1) == v11 ? "SCC" : "MCC";
              scnprintf(
                src,
                26,
                ": vdev %d & %d %s on mac %d",
                *((_DWORD *)v9 + 6),
                *(_DWORD *)((char *)&pm_conc_connection_list + v5 + 60),
                v12,
                (unsigned __int8)v9[12]);
              if ( (unsigned __int64)(v5 - 120) < 0xFFFFFFFFFFFFFF4CLL )
                break;
              v13 = *((_DWORD *)v9 + 6);
              v14 = *((_DWORD *)v2 + 15);
              v2 = (char *)strnlen(a2, 0x12Cu);
              if ( v2 == (char *)-1LL )
                goto LABEL_47;
              v4 = strnlen(src, 0x1Au);
              if ( v4 >= 0x1B )
                goto LABEL_46;
              if ( v4 == 26 )
                goto LABEL_48;
              v7 |= (1 << v13) | (1 << v14);
              if ( (unsigned __int64)v2 <= 0x12B )
              {
                if ( (unsigned __int64)&v2[v4] >= 0x12C )
                  v15 = 299LL - (_QWORD)v2;
                else
                  v15 = v4;
                if ( (unsigned __int64)&v2[v4] >= 0x12C )
                  v16 = 299;
                else
                  v16 = (__int64)&v2[v4];
                v4 = (unsigned __int64)memcpy(&v2[(_QWORD)a2], src, v15);
                a2[v16] = 0;
              }
              v3 = v23;
            }
          }
          --v10;
          v5 += 36;
          if ( !v10 )
            goto LABEL_2;
        }
        __break(1u);
LABEL_46:
        _fortify_panic(2, 26, v4 + 1);
LABEL_47:
        _fortify_panic(2, -1, v2 + 1);
LABEL_48:
        _fortify_panic(4, 26, 27);
      }
    }
LABEL_2:
    ++v6;
    --v8;
    v5 = v22 + 36;
  }
  while ( v6 != 5 );
  for ( i = 0; i != 180; i += 36 )
  {
    v18 = (char *)&pm_conc_connection_list + i;
    if ( *((_BYTE *)&pm_conc_connection_list + i + 28) == 1 && ((v7 >> *((_DWORD *)v18 + 6)) & 1) == 0 )
    {
      qdf_mem_set(src, 0x1Au, 0);
      scnprintf(
        src,
        26,
        ": vdev %d alone on mac %d",
        *((_DWORD *)v18 + 6),
        *((unsigned __int8 *)&pm_conc_connection_list + i + 12));
      v2 = (char *)strnlen(a2, 0x12Cu);
      if ( v2 == (char *)-1LL )
        goto LABEL_47;
      v4 = strnlen(src, 0x1Au);
      if ( v4 >= 0x1B )
        goto LABEL_46;
      if ( v4 == 26 )
        goto LABEL_48;
      if ( (unsigned __int64)v2 <= 0x12B )
      {
        if ( (unsigned __int64)&v2[v4] >= 0x12C )
          v19 = 299LL - (_QWORD)v2;
        else
          v19 = v4;
        if ( (unsigned __int64)&v2[v4] >= 0x12C )
          v20 = 299;
        else
          v20 = (__int64)&v2[v4];
        memcpy(&v2[(_QWORD)a2], src, v19);
        a2[v20] = 0;
      }
    }
  }
  result = qdf_mutex_release((__int64)(v23 + 7));
  _ReadStatusReg(SP_EL0);
  return result;
}
