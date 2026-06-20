__int64 __fastcall extract_vdev_roam_param_tlv(
        int a1,
        _QWORD *a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _DWORD *v11; // x19

  if ( a2 )
  {
    v11 = (_DWORD *)*a2;
    qdf_mem_set(a3, 0xCu, 0);
    *a3 = v11[1];
    a3[1] = v11[2];
    a3[2] = v11[3];
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid roam event buffer",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_vdev_roam_param_tlv");
    return 4;
  }
}
