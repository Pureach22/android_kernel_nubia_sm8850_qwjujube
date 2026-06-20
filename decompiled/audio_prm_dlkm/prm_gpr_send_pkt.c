__int64 __fastcall prm_gpr_send_pkt(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w0
  __int64 v4; // x0
  __int64 v5; // x20
  int v6; // w19
  unsigned int v7; // w19
  _QWORD v9[6]; // [xsp+0h] [xbp-30h] BYREF

  v9[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = mutex_lock(&unk_6D28);
  dword_6D5C = 1;
  dword_6D60 = 0;
  if ( g_prm )
  {
    if ( (is_apm_ready_check_done & 1) == 0 && byte_6D68 == 1 && (unsigned int)gpr_get_q6_state(v2) == 2 )
    {
      printk(&unk_6F2E, "prm_gpr_send_pkt");
      if ( (spf_core_is_apm_ready(0) & 1) == 0 )
      {
        msleep(2);
        if ( (spf_core_is_apm_ready(0) & 1) == 0 )
        {
          msleep(2);
          if ( (spf_core_is_apm_ready(0) & 1) == 0 )
          {
            msleep(2);
            spf_core_is_apm_ready(0);
          }
        }
      }
      is_apm_ready_check_done = 1;
      printk(&unk_7099, "prm_gpr_send_pkt");
    }
    byte_6D58 = 0;
    v3 = gpr_send_pkt(g_prm, a1);
    if ( (v3 & 0x80000000) != 0 )
    {
      v7 = v3;
      printk(&unk_6E19, "prm_gpr_send_pkt");
    }
    else
    {
      if ( (byte_6D58 & 1) == 0 )
      {
        memset(v9, 0, 40);
        init_wait_entry(v9, 0);
        prepare_to_wait_event(&unk_6D10, v9, 2);
        if ( (byte_6D58 & 1) != 0 )
        {
          finish_wait(&unk_6D10, v9);
        }
        else
        {
          v4 = 50;
          do
          {
            v5 = schedule_timeout(v4);
            prepare_to_wait_event(&unk_6D10, v9, 2);
            if ( ((unsigned __int8)byte_6D58 & (v5 == 0)) != 0 )
              v4 = 1;
            else
              v4 = v5;
          }
          while ( (byte_6D58 & 1) == 0 && v4 );
          v6 = v4;
          finish_wait(&unk_6D10, v9);
          if ( !v6 )
          {
            printk(&unk_6DC8, "prm_gpr_send_pkt");
            v7 = -110;
            goto LABEL_18;
          }
        }
      }
      if ( dword_6D60 >= 1 )
      {
        printk(&unk_6F7D, "prm_gpr_send_pkt");
        v7 = -22;
      }
      else
      {
        v7 = 0;
      }
    }
  }
  else
  {
    printk(&unk_6F13, "prm_gpr_send_pkt");
    v7 = -19;
  }
LABEL_18:
  mutex_unlock(&unk_6D28);
  _ReadStatusReg(SP_EL0);
  return v7;
}
