__int64 __fastcall hdd_register_interface(
        __int64 a1,
        char a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w0
  unsigned int v32; // w0
  __int64 v33; // x5
  unsigned int v34; // w0
  const char *v35; // x2
  unsigned int v36; // w0
  unsigned __int64 v44; // x9

  v13 = *(_QWORD *)(a1 + 32);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_register_interface");
  if ( (a2 & 1) != 0 )
  {
    if ( strnchr(v13 + 296, 15, 37) )
    {
      v31 = dev_alloc_name(v13, v13 + 296);
      if ( (v31 & 0x80000000) != 0 )
      {
        v33 = v31;
        v35 = "%s: unable to get dev name: %s, err = 0x%x";
        goto LABEL_13;
      }
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: hdd_register_netdevice(%s) type:%d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hdd_register_interface",
      v13 + 296,
      *(unsigned int *)(a1 + 40));
    if ( (*a3 & 8) == 0 )
    {
      v32 = register_netdevice(v13);
      v33 = v32;
      if ( !v32 )
        goto LABEL_14;
      goto LABEL_10;
    }
    v36 = cfg80211_register_netdevice(v13);
    v33 = v36;
    if ( v36 )
    {
LABEL_10:
      v35 = "%s: register_netdevice(%s) failed, err = 0x%x";
      goto LABEL_13;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: register_netdev(%s) type:%d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_register_interface",
      v13 + 296,
      *(unsigned int *)(a1 + 40));
    v34 = register_netdev(v13);
    if ( v34 )
    {
      v33 = v34;
      v35 = "%s: register_netdev(%s) failed, err = 0x%x";
LABEL_13:
      qdf_trace_msg(0x33u, 2u, v35, v23, v24, v25, v26, v27, v28, v29, v30, "hdd_register_interface", v13 + 296, v33);
      return 16;
    }
  }
LABEL_14:
  _X8 = (unsigned __int64 *)(a1 + 1624);
  __asm { PRFM            #0x11, [X8] }
  do
    v44 = __ldxr(_X8);
  while ( __stxr(v44 | 1, _X8) );
  qdf_trace_msg(0x33u, 8u, "%s: exit", v23, v24, v25, v26, v27, v28, v29, v30, "hdd_register_interface");
  return 0;
}
