__int64 __fastcall ucfg_dp_set_def_tidmap_prty(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x0
  __int64 v13; // x9
  __int64 (__fastcall *v14)(__int64, __int64, __int64, char *); // x9
  __int64 v15; // x1
  unsigned int v16; // w0
  const char *v17; // x2
  __int64 result; // x0
  char v19; // [xsp+0h] [xbp-20h] BYREF
  __int64 v20; // [xsp+1h] [xbp-1Fh]
  _BYTE v21[23]; // [xsp+9h] [xbp-17h]

  *(_QWORD *)&v21[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 216);
    if ( v10 )
    {
      v11 = *(_QWORD *)(v10 + 80);
      if ( v11 )
      {
        v12 = *(_QWORD *)(v11 + 2808);
        if ( v12 )
        {
          if ( *(_QWORD *)v12 )
          {
            v13 = *(_QWORD *)(*(_QWORD *)v12 + 8LL);
            if ( v13 )
            {
              v14 = *(__int64 (__fastcall **)(__int64, __int64, __int64, char *))(v13 + 96);
              if ( v14 )
              {
                v19 = a2;
                v15 = *(unsigned __int8 *)(v10 + 40);
                v20 = 0;
                *(_QWORD *)v21 = 0;
                *(_QWORD *)&v21[7] = 0;
                if ( *((_DWORD *)v14 - 1) != 1785247490 )
                  __break(0x8229u);
                v16 = v14(v12, v15, 18, &v19);
                goto LABEL_17;
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x89u,
              8u,
              "%s: Invalid Instance:",
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              "cdp_txrx_set_pdev_param");
          }
          v16 = 16;
LABEL_17:
          result = qdf_status_to_os_return(v16);
          goto LABEL_18;
        }
      }
      v17 = "%s: dp handle is null";
    }
    else
    {
      v17 = "%s: null pdev";
    }
  }
  else
  {
    v17 = "%s: null vdev";
  }
  qdf_trace_msg(0x45u, 2u, v17, a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_dp_set_def_tidmap_prty");
  result = 4294967274LL;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
