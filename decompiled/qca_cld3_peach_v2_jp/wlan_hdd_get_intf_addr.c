__int64 __fastcall wlan_hdd_get_intf_addr(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 v10; // x23
  __int16 v11; // h15
  __int64 v14; // x8
  unsigned __int8 *v15; // x8
  unsigned __int8 *v16; // x20
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  _BYTE *v30; // x22
  __int64 v31; // x8
  unsigned int v32; // w21
  unsigned __int8 *v33; // x8
  __int64 v34; // x3
  __int64 v35; // x4
  __int64 v36; // x5
  __int64 v37; // x6
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  _BYTE *v47; // x19
  unsigned __int64 v55; // x10
  unsigned __int64 v58; // x10

  _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)(*(_QWORD *)(a1 + 104) + 8 * ((unsigned __int64)a2 >> 6) + 128) >> a2) & 1) != 0 )
  {
    v14 = *(_QWORD *)(a1 + 3832);
    if ( v14 != -1 )
    {
      v10 = __clz(__rbit64(~v14));
      if ( *(_DWORD *)(a1 + 3824) > (unsigned int)v10 )
      {
        _X9 = (unsigned __int64 *)(a1 + 3832);
        __asm { PRFM            #0x11, [X9] }
        do
          v55 = __ldxr(_X9);
        while ( __stxr(v55 | (1LL << v10), _X9) );
        if ( (unsigned int)v10 >= 6 )
          goto LABEL_50;
        v15 = (unsigned __int8 *)(a1 + 6LL * (unsigned int)v10);
        v16 = v15 + 3751;
        if ( v15 == (unsigned __int8 *)-3751LL )
        {
          v19 = 0;
          v17 = 0;
          v18 = 0;
          v20 = 0;
        }
        else
        {
          v17 = *v16;
          v18 = v15[3752];
          v19 = v15[3753];
          v20 = v15[3756];
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Assigning MAC from provisioned list %02x:%02x:%02x:**:**:%02x",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "wlan_hdd_get_provisioned_intf_addr",
          v17,
          v18,
          v19,
          v20);
        if ( *(_DWORD *)(a1 + 3696) | *(unsigned __int16 *)(a1 + 3700) )
        {
          if ( *(_DWORD *)(a1 + 3704) | *(unsigned __int16 *)(a1 + 3708) )
          {
            if ( *(_DWORD *)(a1 + 3712) | *(unsigned __int16 *)(a1 + 3716) )
            {
              if ( *(_DWORD *)(a1 + 3720) | *(unsigned __int16 *)(a1 + 3724) )
              {
                if ( *(_DWORD *)(a1 + 3728) | *(unsigned __int16 *)(a1 + 3732) )
                {
                  if ( *(_DWORD *)(a1 + 3736) | *(unsigned __int16 *)(a1 + 3740) )
                  {
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: Max interfaces are up",
                      v21,
                      v22,
                      v23,
                      v24,
                      v25,
                      v26,
                      v27,
                      v28,
                      "wlan_hdd_get_provisioned_intf_addr");
                    goto LABEL_22;
                  }
                  v29 = 5;
                }
                else
                {
                  v29 = 4;
                }
              }
              else
              {
                v29 = 3;
              }
            }
            else
            {
              v29 = 2;
            }
          }
          else
          {
            v29 = 1;
          }
        }
        else
        {
          v29 = 0;
        }
        v30 = (_BYTE *)(a1 + 3696 + 8 * v29);
        qdf_mem_copy(v30, v16, 6u);
        v30[7] = v10;
        v30[6] = 1;
        if ( v16 )
          goto LABEL_44;
      }
    }
  }
LABEL_22:
  if ( ((*(_QWORD *)(*(_QWORD *)(a1 + 104) + 8 * ((unsigned __int64)a2 >> 6) + 132) >> a2) & 1) == 0 )
    goto LABEL_43;
  v31 = *(_QWORD *)(a1 + 3840);
  if ( v31 == -1 )
    goto LABEL_43;
  v32 = __clz(__rbit64(~v31));
  if ( *(_DWORD *)(a1 + 3828) <= v32 )
    goto LABEL_43;
  _X9 = (unsigned __int64 *)(a1 + 3840);
  __asm { PRFM            #0x11, [X9] }
  do
    v58 = __ldxr(_X9);
  while ( __stxr(v58 | (1LL << v32), _X9) );
  if ( v32 < 6 )
  {
    v33 = (unsigned __int8 *)(a1 + 6LL * v32);
    v16 = v33 + 3787;
    if ( v33 == (unsigned __int8 *)-3787LL )
    {
      v36 = 0;
      v34 = 0;
      v35 = 0;
      v37 = 0;
    }
    else
    {
      v34 = *v16;
      v35 = v33[3788];
      v36 = v33[3789];
      v37 = v33[3792];
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "Assigning MAC from derived list %02x:%02x:%02x:**:**:%02x",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      v34,
      v35,
      v36,
      v37);
    if ( *(_DWORD *)(a1 + 3696) | *(unsigned __int16 *)(a1 + 3700) )
    {
      if ( *(_DWORD *)(a1 + 3704) | *(unsigned __int16 *)(a1 + 3708) )
      {
        if ( *(_DWORD *)(a1 + 3712) | *(unsigned __int16 *)(a1 + 3716) )
        {
          if ( *(_DWORD *)(a1 + 3720) | *(unsigned __int16 *)(a1 + 3724) )
          {
            if ( *(_DWORD *)(a1 + 3728) | *(unsigned __int16 *)(a1 + 3732) )
            {
              if ( *(_DWORD *)(a1 + 3736) | *(unsigned __int16 *)(a1 + 3740) )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Max interfaces are up",
                  v38,
                  v39,
                  v40,
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  "wlan_hdd_get_derived_intf_addr");
LABEL_43:
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: MAC is not available in both the lists",
                  a3,
                  a4,
                  a5,
                  a6,
                  a7,
                  a8,
                  a9,
                  a10,
                  "wlan_hdd_get_intf_addr");
                v16 = nullptr;
                goto LABEL_44;
              }
              v46 = 5;
            }
            else
            {
              v46 = 4;
            }
          }
          else
          {
            v46 = 3;
          }
        }
        else
        {
          v46 = 2;
        }
      }
      else
      {
        v46 = 1;
      }
    }
    else
    {
      v46 = 0;
    }
    v47 = (_BYTE *)(a1 + 3696 + 8 * v46);
    qdf_mem_copy(v47, v16, 6u);
    v47[6] = 0;
    v47[7] = v32;
    if ( !v16 )
      goto LABEL_43;
LABEL_44:
    _ReadStatusReg(SP_EL0);
    return (__int64)v16;
  }
LABEL_50:
  __break(0x5512u);
  *(_WORD *)(v10 + 6852) = v11;
  return wlan_hdd_release_intf_addr();
}
