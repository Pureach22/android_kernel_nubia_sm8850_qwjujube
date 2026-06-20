__int64 __fastcall qlpmm_subsystem_req_cb(__int64 a1, __int64 *a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  _DWORD *v7; // x8
  char *v8; // x10
  char *i; // x9
  int v10; // w13
  __int64 v11; // x14
  char *v12; // x20
  int v13; // w8
  unsigned __int64 v14; // x22
  __int64 v15; // x23
  __int64 *v16; // x24
  __int64 v17; // x25
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  result = qmi_send_response(a1, a2, a3, 3, 7, &lpm_monitor_report_to_apps_resp_msg_v01_ei, &v18);
  v7 = (_DWORD *)qlpmm_pd;
  v8 = *(char **)(qlpmm_pd + 400);
  for ( i = (char *)(qlpmm_pd + 400); v8 != i; v8 = *(char **)v8 )
  {
    if ( (v8[28] & 1) == 0 && *(_DWORD *)(a4 + 8) == -1412571974 && *((_DWORD *)v8 + 9) == *(_DWORD *)a4 )
    {
      v10 = *((_DWORD *)a2 + 2);
      v11 = *a2;
      v8[28] = 1;
      *((_DWORD *)v8 + 6) = v10;
      *((_QWORD *)v8 + 2) = v11;
      ++*v7;
    }
  }
  if ( *v7 )
  {
    v12 = *(char **)i;
    while ( v12 != i )
    {
      if ( *((_DWORD *)v12 + 9) == *(_DWORD *)a4 && v12[28] == 1 )
      {
        snprintf(v12 + 48, 0x29u, (const char *)(a4 + 16));
        *((_DWORD *)v12 + 10) = *(_DWORD *)(a4 + 4);
        v13 = *(_DWORD *)(a4 + 60);
        *((_DWORD *)v12 + 11) = v13;
        if ( v13 )
        {
          v14 = 0;
          v15 = -2880;
          do
          {
            if ( !v15 )
              __break(0x5512u);
            v16 = (__int64 *)&v12[v15];
            v17 = a4 + v15;
            snprintf(&v12[v15 + 3000], 0x29u, (const char *)(a4 + v15 + 2968));
            ++v14;
            v15 += 72;
            *((_DWORD *)v16 + 744) = *(_DWORD *)(v17 + 2944);
            v16[373] = *(_QWORD *)(v17 + 2952);
            v16[374] = *(_QWORD *)(v17 + 2960);
          }
          while ( v14 < *(unsigned int *)(a4 + 60) );
        }
        result = complete(qlpmm_pd + 16);
        v7 = (_DWORD *)qlpmm_pd;
      }
      v12 = *(char **)v12;
      i = (char *)(v7 + 100);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
