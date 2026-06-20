__int64 __fastcall wlan_hdd_set_powersave(
        unsigned __int8 *a1,
        char a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x23
  __int64 v12; // x20
  unsigned int v17; // w0
  __int64 v18; // x2
  unsigned __int8 *v19; // x1
  unsigned int v20; // w19

  v11 = *(_QWORD *)a1;
  v12 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  if ( v12 )
  {
    if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                         a1[8],
                         (__int64)"wlan_hdd_set_powersave",
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         a10,
                         a11) )
    {
      return 4294967274LL;
    }
    else
    {
      v17 = sme_ps_set_powersave(*(_QWORD *)(v12 + 16), a1[8], a2 & 1, a3, a1[1656]);
      if ( (a2 & 1) == 0 && !*(_DWORD *)(v11 + 40) )
      {
        v18 = a1[8];
        v19 = a1 + 300;
        v20 = v17;
        hdd_twt_del_dialog_in_ps_disable(v12, v19, v18);
        v17 = v20;
      }
      return qdf_status_to_os_return(v17);
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: hdd context is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_hdd_set_powersave");
    return 4294967274LL;
  }
}
