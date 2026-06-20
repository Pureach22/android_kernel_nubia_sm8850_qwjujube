__int64 __fastcall sme_set_nss_capability(
        _QWORD *a1,
        unsigned int a2,
        unsigned __int8 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0

  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Nss cap update, NSS %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "sme_set_nss_capability",
    a3);
  sme_update_he_cap_nss((__int64)a1, a2, a3, v16, v17, v18, v19, v20, v21, v22, v23);
  sme_update_eht_cap_nss(a1, a2, a3, v24, v25, v26, v27, v28, v29, v30, v31);
  result = qdf_mutex_acquire((__int64)(a1 + 1606));
  if ( !(_DWORD)result )
  {
    csr_set_vdev_ies_per_band(a1, a2, a4);
    return qdf_mutex_release((__int64)(a1 + 1606));
  }
  return result;
}
