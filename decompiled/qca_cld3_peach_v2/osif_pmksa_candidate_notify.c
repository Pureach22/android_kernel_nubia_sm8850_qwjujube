__int64 __fastcall osif_pmksa_candidate_notify(__int64 a1, unsigned __int8 *a2, unsigned int a3, char a4)
{
  __int64 *v4; // x8
  __int64 v5; // x22
  int v9; // w4
  int v10; // w5
  int v11; // w6
  int v12; // w7
  __int64 v14; // x0
  __int64 v15; // x22
  unsigned int v16; // w0

  v4 = *(__int64 **)(a1 + 680);
  if ( !v4 )
  {
    qdf_trace_msg(72, 2, "%s: Invalid vdev osif priv", "osif_pmksa_candidate_notify");
    return 4;
  }
  v5 = *v4;
  if ( !*v4 )
  {
    qdf_trace_msg(72, 2, "%s: wdev is null", "osif_pmksa_candidate_notify");
    return 4;
  }
  qdf_trace_msg(72, 8, "%s: is going to notify supplicant of:", "osif_pmksa_candidate_notify");
  if ( a2 )
  {
    v9 = *a2;
    v10 = a2[1];
    v11 = a2[2];
    v12 = a2[5];
  }
  else
  {
    v11 = 0;
    v9 = 0;
    v10 = 0;
    v12 = 0;
  }
  v14 = qdf_trace_msg(72, 4, "%s: %02x:%02x:%02x:**:**:%02x", "osif_pmksa_candidate_notify", v9, v10, v11, v12);
  v15 = *(_QWORD *)(v5 + 32);
  v16 = qdf_mem_malloc_flags(v14);
  cfg80211_pmksa_candidate_notify(v15, a3, a2, a4 & 1, v16);
  return 0;
}
