__int64 __fastcall disp_encrpted_log_stats(_QWORD *a1, unsigned int a2, __int64 a3)
{
  unsigned int v3; // w21
  char v4; // w8
  char v7; // w9
  __int64 v9; // x24
  bool v10; // zf
  unsigned int v11; // w21
  const char *v12; // x3
  int v13; // w22
  int v14; // w22
  int v15; // w22
  int v16; // w22
  int v17; // w27
  __int64 v18; // x22
  __int64 v19; // x23
  __int64 v20; // x0
  int v21; // w0
  __int64 v22; // x2
  int v23; // w8
  int v24; // w22
  int v25; // w0
  size_t v26; // x2
  void *v27; // x8
  int v28; // w20
  void *v29; // x0
  __int64 v30; // x1
  __int64 v31; // x2
  __int64 v32; // x3
  __int64 v33; // x4

  v3 = a3;
  v4 = byte_334;
  if ( (byte_333 & 1) != 0 )
  {
    v7 = 1;
  }
  else if ( (byte_334 & 1) != 0 )
  {
    printk(&unk_992A, "_disp_encrpted_log_stats", a3);
    v7 = byte_333;
    v4 = byte_334;
  }
  else
  {
    v7 = 0;
  }
  if ( (unsigned int)qcom_scm_request_encrypted_log(*a1, a1[2], v3, v7 & 1, v4 & 1) )
    return 0;
  v9 = a1[1];
  v10 = v3 == 1;
  v11 = *(_DWORD *)(v9 + 8);
  if ( v10 )
    v12 = "QSEE Log";
  else
    v12 = "TZ Dialog";
  v13 = scnprintf(qword_130, (unsigned int)(display_buf_size - 1), "\n-------- New Encrypted %s --------\n", v12);
  v14 = scnprintf(
          qword_130 + v13,
          (unsigned int)(display_buf_size + ~v13),
          "\nMagic_Num :\n0x%x\n\nVerion :\n%d\n\nEncr_Log_Buff_Size :\n%d\n\nWrap_Count :\n%d\n",
          *(_DWORD *)v9,
          *(_DWORD *)(v9 + 4),
          *(_DWORD *)(v9 + 8),
          *(unsigned __int16 *)(v9 + 12))
      + v13;
  v15 = print_text("\nKey : ", v9 + 14, 256, qword_130 + v14, (unsigned int)display_buf_size) + v14;
  v16 = print_text("\nNonce : ", v9 + 270, 12, qword_130 + v15, (unsigned int)(display_buf_size - v15)) + v15;
  v17 = print_text("\nTag : ", v9 + 282, 16, qword_130 + v16, (unsigned int)(display_buf_size - v16)) + v16;
  v18 = qword_130 + v17;
  v19 = (unsigned int)(display_buf_size + ~v17);
  v20 = ktime_mono_to_any(g_hlos_uptime_baseline, 0);
  v21 = scnprintf(
          v18,
          v19,
          "\n"
          "Hlos_Real_Time_Baseline :\n"
          "%llx\n"
          "\n"
          "Hlos_Uptime_Baseline :\n"
          "%llx\n"
          "\n"
          "\n"
          "TZ_Uptime_Ticks_Baseline :\n"
          "%llx\n"
          "\n"
          "TZ_Tick_Frequency :\n"
          "%llx\n",
          v20,
          g_hlos_uptime_baseline,
          g_tz_ticks_baseline,
          g_tz_ticks_frequency);
  v23 = display_buf_size;
  v24 = v21 + v17;
  if ( v21 + v17 > display_buf_size - v11 )
  {
    printk(&unk_A645, "_disp_encrpted_log_stats", v22);
    v23 = display_buf_size;
  }
  v25 = print_text("\nLog : ", v9 + 298, v11, qword_130 + v24, (unsigned int)(v23 - v24));
  v27 = (void *)a1[1];
  v26 = a1[2];
  v28 = v25;
  v29 = memset(v27, 0, v26);
  if ( a2 >= 0xB )
  {
    __break(0x5512u);
    return print_text(v29, v30, v31, v32, v33);
  }
  else
  {
    tzdbg[5 * a2 + 18] = qword_130;
    return (unsigned int)(v28 + v24);
  }
}
