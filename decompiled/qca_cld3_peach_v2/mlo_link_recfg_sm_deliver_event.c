__int64 __fastcall mlo_link_recfg_sm_deliver_event(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w19

  if ( a1 )
  {
    qdf_mutex_acquire(*(_QWORD *)(a1 + 3888) + 760LL);
    v16 = wlan_sm_dispatch(
            *(_QWORD *)(*(_QWORD *)(a1 + 3888) + 824LL),
            a2,
            a3,
            a4,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15);
    qdf_mutex_release(*(_QWORD *)(a1 + 3888) + 760LL);
  }
  else
  {
    return 29;
  }
  return v16;
}
