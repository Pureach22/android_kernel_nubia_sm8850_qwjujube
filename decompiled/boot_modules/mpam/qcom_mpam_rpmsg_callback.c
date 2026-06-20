__int64 __fastcall qcom_mpam_rpmsg_callback(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x11

  if ( a2 && a3 > 0x23 )
  {
    if ( *(_DWORD *)a2 == 3 )
    {
      v3 = *(_QWORD *)(a2 + 28);
      cdsp_status = *(_QWORD *)(a2 + 20);
      qword_6988 = v3;
      if ( !cdsp_version )
      {
        cdsp_version = *(_DWORD *)(a2 + 8);
        cdsp_limit_cfg = cdsp_status;
        dword_6948 = qword_6988;
        return 0;
      }
      complete(&rpmsg_complete);
    }
    return 0;
  }
  else
  {
    dev_err(a1, "Invalid message in rpmsg callback, length: %d, expected: %lu\n", a3, 36);
    return 4294967274LL;
  }
}
