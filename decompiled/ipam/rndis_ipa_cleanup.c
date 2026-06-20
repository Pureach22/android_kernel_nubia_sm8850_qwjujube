void __fastcall rndis_ipa_cleanup(_QWORD *a1)
{
  __int64 v2; // x20
  int state; // w21
  long double v4; // q0
  __int64 v5; // x0
  __int64 v6; // x8
  const char *v7; // x4
  __int64 v8; // x20
  __int64 v9; // x1
  __int64 v10; // x20
  int v11; // w0
  __int64 v12; // x0
  __int64 v13; // x1

  if ( ipa_rndis_logbuf )
  {
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_cleanup", 1487);
    if ( ipa_rndis_logbuf )
      ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d private=0x%pK\n", "rndis_ipa_cleanup", 1489, a1);
  }
  if ( a1 )
  {
    v2 = raw_spin_lock_irqsave(a1 + 25);
    state = rndis_ipa_next_state(*((_DWORD *)a1 + 18), 5);
    raw_spin_unlock_irqrestore(a1 + 25, v2);
    if ( state == 5 )
    {
      if ( (unsigned int)__ratelimit(&rndis_ipa_cleanup__rs, "rndis_ipa_cleanup") )
      {
        _ReadStatusReg(SP_EL0);
        printk(&unk_3B42A3, "rndis_ipa_cleanup");
        v5 = ipa_rndis_logbuf;
        if ( ipa_rndis_logbuf )
          goto LABEL_8;
      }
      else
      {
        v5 = ipa_rndis_logbuf;
        if ( ipa_rndis_logbuf )
LABEL_8:
          ipc_log_string(v5, "RNDIS_IPA %s:%d use disconnect()before clean()\n", "rndis_ipa_cleanup", 1502);
      }
    }
    else
    {
      if ( ipa_rndis_logbuf )
      {
        v6 = *((unsigned int *)a1 + 18);
        if ( (unsigned int)v6 > 4 )
          v7 = "Not supported";
        else
          v7 = off_1F6620[v6];
        v4 = ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d Driver state: %s\n", "rndis_ipa_cleanup", 1507, v7);
        v8 = *a1 + 296LL;
        if ( ipa_rndis_logbuf )
          v4 = ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_deregister_properties", 1955);
      }
      else
      {
        v8 = *a1 + 296LL;
      }
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, long double))ipa_deregister_intf)(v8, v4) )
      {
        if ( ipa_rndis_logbuf )
          ipc_log_string(
            ipa_rndis_logbuf,
            "RNDIS_IPA %s:%d Fail on Tx prop deregister\n",
            "rndis_ipa_deregister_properties",
            1959);
        _ReadStatusReg(SP_EL0);
        printk(&unk_3D1B5D, "rndis_ipa_cleanup");
        if ( ipa_rndis_logbuf )
          ipc_log_string(
            ipa_rndis_logbuf,
            "RNDIS_IPA %s:%d Fail to deregister Tx/Rx properties\n",
            "rndis_ipa_cleanup",
            1511);
      }
      else
      {
        if ( ipa_rndis_logbuf )
        {
          ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d end\n", "rndis_ipa_deregister_properties", 1962);
          if ( ipa_rndis_logbuf )
            ipc_log_string(
              ipa_rndis_logbuf,
              "RNDIS_IPA %s:%d deregister Tx/Rx properties was successful\n",
              "rndis_ipa_cleanup",
              1514);
        }
        if ( *((_BYTE *)a1 + 224) == 1 )
        {
          if ( (unsigned int)ipa_hdrs_hpc_destroy(*((_DWORD *)a1 + 57)) )
          {
            _ReadStatusReg(SP_EL0);
            printk(&unk_3C62C8, "rndis_ipa_cleanup");
            if ( ipa_rndis_logbuf )
              ipc_log_string(
                ipa_rndis_logbuf,
                "RNDIS_IPA %s:%d ipa_hdrs_hpc_destroy failed\n",
                "rndis_ipa_cleanup",
                1519);
          }
          else if ( ipa_rndis_logbuf )
          {
            ipc_log_string(
              ipa_rndis_logbuf,
              "RNDIS_IPA %s:%d ipa_hdrs_hpc_destroy success\n",
              "rndis_ipa_cleanup",
              1521);
          }
        }
        if ( (unsigned int)rndis_ipa_hdrs_destroy((__int64)a1) )
        {
          _ReadStatusReg(SP_EL0);
          printk(&unk_3D7912, "rndis_ipa_cleanup");
          if ( ipa_rndis_logbuf )
            ipc_log_string(
              ipa_rndis_logbuf,
              "RNDIS_IPA %s:%d Failed removing RNDIS headers from IPA core. Continue anyway\n",
              "rndis_ipa_cleanup",
              1527);
        }
        else if ( ipa_rndis_logbuf )
        {
          ipc_log_string(
            ipa_rndis_logbuf,
            "RNDIS_IPA %s:%d RNDIS headers were removed from IPA core\n",
            "rndis_ipa_cleanup",
            1529);
        }
        debugfs_remove(a1[4]);
        if ( ipa_rndis_logbuf )
          ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d debugfs remove was done\n", "rndis_ipa_cleanup", 1532);
        unregister_netdev(*a1, v9);
        if ( ipa_rndis_logbuf )
          ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d netdev unregistered\n", "rndis_ipa_cleanup", 1535);
        v10 = raw_spin_lock_irqsave(a1 + 25);
        v11 = rndis_ipa_next_state(*((_DWORD *)a1 + 18), 5);
        if ( v11 == 5 )
        {
          raw_spin_unlock_irqrestore(a1 + 25, v10);
          if ( (unsigned int)__ratelimit(&rndis_ipa_cleanup__rs_101, "rndis_ipa_cleanup") )
          {
            _ReadStatusReg(SP_EL0);
            printk(&unk_3B42A3, "rndis_ipa_cleanup");
            v12 = ipa_rndis_logbuf;
            if ( !ipa_rndis_logbuf )
              return;
          }
          else
          {
            v12 = ipa_rndis_logbuf;
            if ( !ipa_rndis_logbuf )
              return;
          }
          ipc_log_string(v12, "RNDIS_IPA %s:%d use disconnect()before clean()\n", "rndis_ipa_cleanup", 1542);
          return;
        }
        *((_DWORD *)a1 + 18) = v11;
        raw_spin_unlock_irqrestore(a1 + 25, v10);
        free_netdev(*a1);
        printk(&unk_3F147A, v13);
        if ( ipa_rndis_logbuf )
          ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d end\n", "rndis_ipa_cleanup", 1550);
      }
    }
  }
  else
  {
    _ReadStatusReg(SP_EL0);
    printk(&unk_3E01BA, "rndis_ipa_cleanup");
    if ( ipa_rndis_logbuf )
      ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d null pointer #ptr\n", "rndis_ipa_cleanup", 1492);
  }
}
