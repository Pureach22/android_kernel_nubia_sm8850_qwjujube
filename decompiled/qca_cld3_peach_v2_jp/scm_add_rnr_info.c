__int64 __fastcall scm_add_rnr_info(__int64 result, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x22
  __int64 v5; // x20
  unsigned int v6; // w9
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w8
  unsigned __int64 v16; // x25
  unsigned __int64 v17; // x23
  unsigned int v18; // w24
  char v19; // w20
  __int64 v20; // x0
  unsigned __int64 v21; // x26
  int v22; // w23
  __int64 chan_meta; // x0
  __int64 v24; // x22
  _QWORD *v25; // x21
  int v26; // w8
  bool v27; // cf
  int v28; // w27
  int *v29; // x19
  int v30; // w8
  int *v31; // x10
  unsigned __int64 v32; // x9
  int v33; // t1
  int *v34; // x9
  __int64 v35; // [xsp+8h] [xbp-68h]
  __int64 v36; // [xsp+38h] [xbp-38h]
  int v37; // [xsp+4Ch] [xbp-24h]
  _QWORD *v38; // [xsp+50h] [xbp-20h] BYREF
  _QWORD *v39[3]; // [xsp+58h] [xbp-18h] BYREF

  v39[2] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 80);
  if ( v2 )
  {
    v3 = result;
    result = scm_get_rnr_channel_db(*(_QWORD *)(result + 80));
    if ( result )
    {
      v5 = result;
      qdf_mutex_acquire(result + 2888);
      v6 = (unsigned __int8)++*(_BYTE *)(v5 + 2880);
      if ( v6 >= 2 )
      {
        *(_BYTE *)(v5 + 2880) = 0;
        scm_rnr_db_flush(v2);
        scm_update_rnr_from_scan_cache(v3, v7, v8, v9, v10, v11, v12, v13, v14);
      }
      v38 = nullptr;
      if ( a2 )
      {
        v15 = *(unsigned __int8 *)(a2 + 120);
        if ( *(_BYTE *)(a2 + 120) )
        {
          v35 = v5;
          v16 = 0;
          v17 = 0;
          v18 = 0;
          v19 = 15;
          v20 = v2;
          v39[0] = nullptr;
          v36 = v2;
          while ( 1 )
          {
            if ( v16 == 102 )
              __break(0x5512u);
            v21 = v17;
            v22 = *(_DWORD *)(a2 + 124 + 12 * v16);
            chan_meta = scm_get_chan_meta(v20, v22);
            if ( chan_meta )
            {
              v24 = chan_meta;
              if ( !qdf_list_empty((_QWORD *)(chan_meta + 24)) )
              {
                qdf_list_peek_front((_QWORD *)(v24 + 24), v39);
                v25 = v39[0];
                if ( v39[0] )
                {
                  if ( v19 )
                    break;
                }
              }
            }
            v17 = v21;
LABEL_9:
            ++v16;
            v20 = v36;
            if ( v16 >= *(unsigned __int8 *)(a2 + 120) )
            {
              v5 = v35;
              v15 = (unsigned __int8)v17;
              goto LABEL_38;
            }
          }
          v26 = v22 << 16;
          v17 = v21;
          v37 = v26;
          while ( 1 )
          {
            if ( *((_DWORD *)v25 + 7) | *((unsigned __int16 *)v25 + 16) )
              v27 = v18 >= 0xA;
            else
              v27 = 1;
            v28 = !v27;
            if ( v28 == 1 )
            {
              v29 = (int *)(a2 + 2164 + 12LL * v18);
              qdf_mem_copy(v29 + 1, (char *)v25 + 28, 6u);
              ++v18;
              *v29 = v37;
            }
            v30 = *((_DWORD *)v25 + 6);
            if ( v30 && v17 <= 9 )
            {
              if ( v21 >= v17 )
              {
LABEL_30:
                v34 = (int *)(a2 + 2084 + 8 * v17++);
                v34[1] = v30;
                *v34 = v37;
                LOBYTE(v30) = -1;
                goto LABEL_32;
              }
              v31 = (int *)(a2 + 2088 + 8 * v21);
              v32 = v17 - v21;
              while ( 1 )
              {
                v33 = *v31;
                v31 += 2;
                if ( v30 == v33 )
                  break;
                if ( !--v32 )
                  goto LABEL_30;
              }
            }
            v30 = v28 << 31 >> 31;
LABEL_32:
            v19 += v30;
            if ( !(unsigned int)qdf_list_peek_next((_QWORD *)(v24 + 24), v39[0], &v38) )
            {
              v25 = v38;
              v38 = nullptr;
              v39[0] = v25;
              if ( v25 )
              {
                if ( v19 )
                  continue;
              }
            }
            goto LABEL_9;
          }
        }
        v18 = 0;
LABEL_38:
        *(_DWORD *)(a2 + 2080) = v18;
        *(_DWORD *)(a2 + 2076) = v15;
      }
      result = qdf_mutex_release(v5 + 2888);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
