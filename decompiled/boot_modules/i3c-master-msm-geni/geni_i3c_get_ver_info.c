void __fastcall geni_i3c_get_ver_info(_QWORD *a1)
{
  _DWORD *v2; // x24
  unsigned int qup_hw_version; // w0
  unsigned int v4; // w20
  int v5; // w21
  int v6; // w22
  __int64 v7; // x8
  unsigned __int8 v8; // w0
  __int64 v9; // x8
  unsigned __int8 v10; // w0
  int v11; // w3
  int v12; // w4
  __int64 v13; // x0

  v2 = a1 + 2560;
  qup_hw_version = geni_se_get_qup_hw_version();
  v4 = qup_hw_version >> 28;
  v5 = HIWORD(qup_hw_version) & 0xFFF;
  v6 = (unsigned __int16)qup_hw_version;
  ipc_log_string(
    a1[316],
    "%s hw_ver: 0x%x Major:%d Minor:%d step:%d\n",
    "geni_i3c_get_ver_info",
    qup_hw_version,
    qup_hw_version >> 28,
    v5,
    (unsigned __int16)qup_hw_version);
  if ( a1[1] )
    i3c_trace_log();
  v7 = *a1;
  v2[266] = v4;
  v2[267] = v5;
  v2[268] = v6;
  v8 = readl_relaxed((unsigned int *)(v7 + 104));
  v9 = *a1;
  v2[269] = v8;
  v10 = readl_relaxed((unsigned int *)(v9 + 108));
  v11 = v2[269];
  v12 = v10;
  v13 = a1[316];
  v2[270] = v12;
  ipc_log_string(v13, "%s:FW Ver:0x%x%x\n", "geni_i3c_get_ver_info", v11, v12);
  if ( a1[1] )
    i3c_trace_log();
}
