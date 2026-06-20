__int64 __fastcall msm_vidc_remove_buffer_stats(__int64 a1, _DWORD *a2, __int64 a3)
{
  _QWORD *v7; // x25
  _QWORD *v8; // x26
  __int64 v9; // x8
  __int64 v10; // x9
  _QWORD *v11; // x1
  int v12; // w9
  int v13; // w10
  int v14; // w9
  bool v15; // zf
  _BOOL4 v16; // w9
  int v17; // w13
  int v18; // w11
  __int64 v19; // x9
  int v20; // w11
  bool v21; // w8
  int v22; // w8
  int v23; // w9
  int v24; // w9
  int v25; // w11
  _QWORD *v26; // x9

  if ( (msm_vidc_debug & 4) == 0 )
    return 0;
  if ( (unsigned int)(a2[6] - 1) <= 1 )
  {
    v7 = (_QWORD *)(a1 + 4088);
    a2[30] = (ktime_get(a1) / 0x3E8uLL - *(_QWORD *)(a1 + 38424)) / 0x3E8;
    v8 = (_QWORD *)*v7;
    if ( (_QWORD *)*v7 == v7 )
      return 0;
    while ( 1 )
    {
      v9 = v8[3];
      v10 = *((unsigned int *)v8 + 14);
      v11 = v8;
      v8 = (_QWORD *)*v8;
      if ( v9 - v10 == a3 )
      {
        v12 = a2[6];
        if ( v12 == 2 )
        {
          if ( *((_DWORD *)v11 + 11) )
            goto LABEL_7;
          *((_DWORD *)v11 + 10) = a2[29];
          v22 = a2[30];
          *((_DWORD *)v11 + 11) = v22;
          v23 = *(_DWORD *)(a1 + 3572);
          v15 = v23 == 0;
          v24 = v23 != 0;
          if ( v15 )
            v25 = 2;
          else
            v25 = 3;
          if ( *(_DWORD *)(a1 + 3576) )
            v24 = v25;
          if ( *(_DWORD *)(a1 + 3556) )
            v24 |= 4u;
          if ( *(_DWORD *)(a1 + 3560) )
            v24 |= 8u;
          *((_DWORD *)v11 + 13) |= v24;
          if ( *(_DWORD *)(a1 + 308) == 1 )
            *((_DWORD *)v11 + 12) = a2[12];
          if ( !*((_DWORD *)v11 + 9) || !v22 )
            goto LABEL_7;
          v19 = v11[1];
LABEL_44:
          if ( *(_QWORD **)v19 == v11 && (_QWORD *)v8[1] == v11 )
          {
            v8[1] = v19;
            *(_QWORD *)v19 = v8;
          }
          else
          {
            _list_del_entry_valid_or_report(v11);
            v11 = v26;
          }
          *v11 = v11;
          v11[1] = v11;
          if ( v11
            && *((_DWORD *)v11 + 8)
            && *((_DWORD *)v11 + 9)
            && *((_DWORD *)v11 + 10)
            && a1
            && *((_DWORD *)v11 + 11)
            && (msm_vidc_debug & 4) != 0 )
          {
            printk(&unk_8E756, "low ", a1 + 340, *((unsigned int *)v11 + 4), v11[3]);
          }
          msm_vidc_pool_free(a1);
          goto LABEL_7;
        }
        if ( v12 == 1 && !*((_DWORD *)v11 + 9) )
        {
          v13 = a2[30];
          *((_DWORD *)v11 + 9) = v13;
          v14 = *(_DWORD *)(a1 + 3572);
          v15 = v14 == 0;
          v16 = v14 != 0;
          if ( v15 )
            v17 = 2;
          else
            v17 = 3;
          if ( *(_DWORD *)(a1 + 3576) )
            v16 = v17;
          v18 = v16 | 4;
          if ( !*(_DWORD *)(a1 + 3556) )
            v18 = v16;
          v19 = v11[1];
          if ( *(_DWORD *)(a1 + 3560) )
            v18 |= 8u;
          v20 = v18 | *((_DWORD *)v11 + 13);
          *((_DWORD *)v11 + 13) = v20;
          if ( (_QWORD *)v19 != v7 && (*(_BYTE *)(v19 + 52) & 8) != 0 )
            *((_DWORD *)v11 + 14) = v9 - *(_DWORD *)(v19 + 24);
          if ( v13 )
          {
            v21 = *((_DWORD *)v11 + 11) != 0;
            if ( (v20 & 4) != 0 )
              goto LABEL_44;
          }
          else
          {
            v21 = 0;
            if ( (v20 & 4) != 0 )
              goto LABEL_44;
          }
          if ( v21 )
            goto LABEL_44;
        }
      }
LABEL_7:
      if ( v8 == v7 )
        return 0;
    }
  }
  return 4294967274LL;
}
