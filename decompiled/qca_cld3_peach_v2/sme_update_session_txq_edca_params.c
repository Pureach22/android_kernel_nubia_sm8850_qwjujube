__int64 __fastcall sme_update_session_txq_edca_params(
        __int64 a1,
        unsigned __int8 a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 session_by_vdev_id; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  __int64 v25; // x0
  __int64 v26; // x20

  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( session_by_vdev_id )
  {
    v23 = session_by_vdev_id;
    if ( (unsigned int)qdf_mutex_acquire(a1 + 12848) )
    {
      return 3;
    }
    else
    {
      v25 = _qdf_mem_malloc(0xAu, "sme_update_session_txq_edca_params", 12232);
      if ( v25 )
      {
        *(_BYTE *)(v25 + 4) = a2;
        v26 = v25;
        *(_WORD *)v25 = 5282;
        qdf_mem_copy((void *)(v25 + 5), a3, 5u);
        *(_WORD *)(v26 + 2) = 10;
        LODWORD(v26) = umac_send_mb_message_to_mac(v26);
        qdf_mutex_release(a1 + 12848);
        if ( (_DWORD)v26 )
        {
          return 23;
        }
        else
        {
          *(_BYTE *)(v23 + 13280) = 1;
          return 0;
        }
      }
      else
      {
        qdf_mutex_release(a1 + 12848);
        return 2;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Session does not exist for given session_id %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "sme_update_session_txq_edca_params",
      a2);
    return 4;
  }
}
