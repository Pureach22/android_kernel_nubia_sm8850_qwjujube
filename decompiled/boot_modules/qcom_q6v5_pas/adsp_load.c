__int64 __fastcall adsp_load(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x22
  __int64 v3; // x20
  __int64 v4; // x0
  unsigned int no_init; // w19
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v10; // x0

  v2 = *(_QWORD **)(a1 + 40);
  if ( *((_BYTE *)v2 + 784) == 1 )
    v3 = *v2;
  else
    v3 = 0;
  v4 = *((unsigned int *)v2 + 116);
  v2[63] = a2;
  if ( (_DWORD)v4 )
  {
    no_init = qcom_scm_pas_shutdown(v4);
    v6 = v2[9];
    if ( !v6 )
    {
LABEL_9:
      if ( !*((_DWORD *)v2 + 115) )
        goto LABEL_13;
      goto LABEL_10;
    }
  }
  else
  {
    no_init = 0;
    v6 = v2[9];
    if ( !v6 )
      goto LABEL_9;
  }
  if ( (icc_set_bw(v6, 0xFFFFFFFFLL, 0xFFFFFFFFLL) & 0x80000000) == 0 )
    goto LABEL_9;
  dev_err(v2[3], "failed to set crypto_path bandwidth request\n");
  icc_set_bw(v2[9], 0, 0);
  if ( !*((_DWORD *)v2 + 115) )
    goto LABEL_13;
LABEL_10:
  no_init = request_firmware(v2 + 64, v2[56], *v2);
  v7 = *v2;
  if ( no_init )
  {
    dev_err(v7, "request_firmware failed for %s: %d\n", (const char *)v2[56], no_init);
    goto LABEL_13;
  }
  no_init = qcom_mdt_pas_init(
              v7,
              v2[64],
              v2[56],
              *((unsigned int *)v2 + 115),
              v2[80],
              v2 + 148,
              *((unsigned __int8 *)v2 + 784));
  if ( !no_init )
  {
    no_init = qcom_mdt_load_no_init(*v2, v2[64], v2[56], *((unsigned int *)v2 + 115), v2[87], v2[80], v2[89], v2 + 82);
    if ( !no_init )
      goto LABEL_13;
    v10 = *((unsigned int *)v2 + 115);
    if ( (_DWORD)v10 )
    {
      if ( *((_BYTE *)v2 + 784) != 1 || (qcom_scm_pas_shutdown(v10), *((_DWORD *)v2 + 115)) )
        qcom_scm_pas_metadata_release(v2 + 148, v3);
    }
  }
  release_firmware(v2[64]);
LABEL_13:
  v8 = v2[9];
  if ( v8 && (icc_set_bw(v8, 0, 0) & 0x80000000) != 0 )
  {
    dev_err(v2[3], "failed to set crypto_path bandwidth request\n");
    icc_set_bw(v2[9], 0, 0);
  }
  return no_init;
}
