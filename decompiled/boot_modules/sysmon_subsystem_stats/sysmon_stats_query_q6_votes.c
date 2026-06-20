__int64 __fastcall sysmon_stats_query_q6_votes(int a1, _DWORD *a2)
{
  _DWORD *v3; // x8
  __int64 result; // x0
  _DWORD *v5; // x8
  int v6; // w10

  if ( !a2 )
  {
    printk(&unk_9E79, "sysmon_subsystem_stats");
    return 4294967274LL;
  }
  switch ( a1 )
  {
    case 5:
      if ( (byte_9601 & 1) == 0 )
        sysmon_smem_init_cdsp();
      result = 4294967170LL;
      v5 = (_DWORD *)qword_9628;
      if ( qword_9628 && (unsigned __int64)qword_9628 <= 0xFFFFFFFFFFFFF000LL )
      {
        v6 = *(_DWORD *)qword_9628;
        result = 0;
        *a2 = *(_DWORD *)(qword_9628 + 4);
        a2[1] = v5[2];
        a2[2] = v5[3];
        a2[3] = v5[4];
        a2[4] = v5[5];
        a2[5] = v5[6];
        if ( (v6 & 0xFFFE) != 0 )
        {
          a2[6] = v5[9];
          a2[7] = v5[10];
          return result;
        }
LABEL_20:
        *((_QWORD *)a2 + 3) = -1;
      }
      break;
    case 3:
      if ( (byte_9602 & 1) == 0 )
        sysmon_smem_init_slpi();
      v3 = (_DWORD *)qword_9630;
      result = 4294967170LL;
      if ( qword_9630 )
      {
LABEL_18:
        if ( (unsigned __int64)v3 > 0xFFFFFFFFFFFFF000LL )
          return result;
        result = 0;
        *a2 = v3[1];
        a2[1] = v3[2];
        a2[2] = v3[3];
        a2[3] = v3[4];
        a2[4] = v3[5];
        a2[5] = v3[6];
        goto LABEL_20;
      }
      break;
    case 2:
      if ( (g_sysmon_stats & 1) == 0 )
        sysmon_smem_init_adsp();
      v3 = (_DWORD *)qword_9620;
      result = 4294967170LL;
      if ( !qword_9620 )
        return result;
      goto LABEL_18;
    default:
      printk(&unk_986A, "sysmon_subsystem_stats");
      return 4294967274LL;
  }
  return result;
}
