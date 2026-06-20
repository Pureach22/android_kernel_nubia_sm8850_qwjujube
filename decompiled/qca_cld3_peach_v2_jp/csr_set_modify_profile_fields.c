__int64 __fastcall csr_set_modify_profile_fields(
        __int64 a1,
        unsigned int a2,
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
  __int64 v11; // x8

  if ( a2 <= 5 && (v11 = *(_QWORD *)(a1 + 17224) + 96LL * a2) != 0 )
  {
    qdf_mem_copy((void *)(v11 + 40), a3, 1u);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Session_id invalid %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "csr_set_modify_profile_fields",
      a2);
    return 4;
  }
}
