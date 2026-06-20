__int64 __fastcall summary_show(__int64 a1)
{
  _QWORD *v2; // x20
  unsigned __int64 v3; // x21
  unsigned __int64 v4; // x23
  unsigned __int64 v5; // x26
  unsigned __int64 v6; // x24
  unsigned __int64 v7; // x28
  unsigned __int64 v8; // x27
  unsigned __int64 v9; // x19
  unsigned __int64 v10; // x25
  unsigned __int64 v11; // x22
  unsigned __int64 v12; // x0
  unsigned __int64 v13; // x17
  unsigned __int64 v14; // x8
  int v15; // w10
  unsigned __int64 v16; // x11
  int v17; // w11
  unsigned __int64 v18; // x11
  unsigned __int64 v19; // x11
  unsigned __int64 v20; // x11
  unsigned __int64 v21; // x11
  unsigned __int64 v22; // x20
  unsigned __int64 v23; // x23
  unsigned __int64 v24; // x28
  unsigned __int64 v25; // x27
  unsigned __int64 v26; // x26
  unsigned __int64 v27; // x22
  unsigned __int64 v28; // x24
  unsigned __int64 v29; // x25
  __int64 v31; // [xsp+0h] [xbp-30h]
  unsigned __int64 v32; // [xsp+8h] [xbp-28h]
  unsigned __int64 v33; // [xsp+10h] [xbp-20h]
  unsigned __int64 v34; // [xsp+18h] [xbp-18h]
  unsigned __int64 v35; // [xsp+20h] [xbp-10h]
  unsigned __int64 v36; // [xsp+28h] [xbp-8h]

  mutex_lock(&vmperm_list_lock);
  v2 = vmperm_list;
  if ( vmperm_list == (_UNKNOWN *)&vmperm_list )
  {
    v32 = 0;
    v33 = 0;
    v23 = 0;
    v24 = 0;
    v34 = 0;
    v22 = 0;
    v25 = 0;
    v28 = 0;
    v26 = 0;
    v29 = 0;
    v27 = 0;
  }
  else
  {
    v31 = a1;
    v3 = 0;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    v11 = 0;
    v35 = 0;
    v36 = 0;
    do
    {
      mutex_lock(v2 + 11);
      v14 = *((unsigned int *)v2 + 12);
      if ( (_DWORD)v14 )
      {
        v12 = v35;
        v13 = v36;
        v15 = 0;
        do
        {
          v17 = *(_DWORD *)(v2[4] + 4LL * v15);
          if ( v17 <= 10 )
          {
            if ( v17 == 9 )
            {
              v21 = v2[9];
              v6 += v21;
              v7 += v21 / v14;
              v11 += v7;
            }
            else if ( v17 == 10 )
            {
              v19 = v2[9];
              v9 += v19;
              v12 += v19 / v14;
              v11 += v12;
            }
          }
          else
          {
            switch ( v17 )
            {
              case 11:
                v16 = v2[9];
                v10 += v16;
                v13 += v16 / v14;
                v11 += v13;
                break;
              case 49:
                v20 = v2[9];
                v3 += v20;
                v4 += v20 / v14;
                v11 += v4;
                break;
              case 45:
                v18 = v2[9];
                v8 += v18;
                v5 += v18 / v14;
                v11 += v5;
                break;
            }
          }
          ++v15;
        }
        while ( (_DWORD)v14 != v15 );
      }
      else
      {
        v12 = v35;
        v13 = v36;
      }
      v35 = v12;
      v36 = v13;
      mutex_unlock(v2 + 11);
      v2 = (_QWORD *)*v2;
    }
    while ( v2 != &vmperm_list );
    v22 = v8 >> 20;
    v23 = v4 >> 20;
    v24 = v7 >> 20;
    v25 = v9 >> 20;
    v32 = v5 >> 20;
    v33 = v3 >> 20;
    v26 = v10 >> 20;
    v27 = v11 >> 20;
    a1 = v31;
    v34 = v6 >> 20;
    v28 = v35 >> 20;
    v29 = v36 >> 20;
  }
  mutex_unlock(&vmperm_list_lock);
  seq_printf(a1, "%10s %10s %10s\n", "VMID", "SIZE-MB", "PSS-SIZE-MB");
  seq_printf(a1, "%#10x %10zu %10zu\n", 45, v22, v32);
  seq_printf(a1, "%#10x %10zu %10zu\n", 49, v33, v23);
  seq_printf(a1, "%#10x %10zu %10zu\n", 9, v34, v24);
  seq_printf(a1, "%#10x %10zu %10zu\n", 10, v25, v28);
  seq_printf(a1, "%#10x %10zu %10zu\n", 11, v26, v29);
  seq_printf(a1, "\nTotal Pss: %zu\n", v27);
  return 0;
}
