__int64 wcd_usbss_surge_kthread_fn()
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0
  int updated; // w21
  int v5; // w26
  int v6; // w21
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (((__int64 (*)(void))kthread_should_stop)() & 1) == 0 )
  {
    do
    {
      if ( (acquire_runtime_env(wcd_usbss_ctxt_) & 0x80000000) != 0 )
        goto LABEL_7;
      if ( *(_BYTE *)(wcd_usbss_ctxt_ + 372) == 1 )
      {
        v3 = *(_QWORD *)wcd_usbss_ctxt_;
        v7 = 0;
        if ( !(unsigned int)regmap_read(v3, 161, &v7) )
        {
          if ( v7 != 255 )
          {
            dev_err(*(_QWORD *)(wcd_usbss_ctxt_ + 8), "%s: Surge check #1 failed\n", "wcd_usbss_is_in_reset_state");
LABEL_38:
            regcache_mark_dirty(*(_QWORD *)wcd_usbss_ctxt_);
            regcache_sync(*(_QWORD *)wcd_usbss_ctxt_);
            regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 161, 255, 255, 0, 0, 0);
            regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1049, 8, 0, 0, 0, 0);
            regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 1049, 8, 8, 0, 0, 0);
            if ( (*(_BYTE *)(wcd_usbss_ctxt_ + 368) & 0xB8) != 0 )
              blocking_notifier_call_chain(wcd_usbss_ctxt_ + 72, 3, 0);
            goto LABEL_6;
          }
          if ( !(unsigned int)regmap_read(*(_QWORD *)wcd_usbss_ctxt_, 21, &v7) )
          {
            if ( (v7 & 2) != 0 )
            {
              if ( (unsigned int)regmap_read(*(_QWORD *)wcd_usbss_ctxt_, 21, &v7) )
                goto LABEL_6;
              if ( (v7 & 2) != 0 )
              {
                if ( (unsigned int)regmap_read(*(_QWORD *)wcd_usbss_ctxt_, 21, &v7) )
                  goto LABEL_6;
                if ( (v7 & 2) != 0 )
                {
                  if ( (unsigned int)regmap_read(*(_QWORD *)wcd_usbss_ctxt_, 21, &v7) )
                    goto LABEL_6;
                  if ( (v7 & 2) != 0 )
                  {
                    if ( (unsigned int)regmap_read(*(_QWORD *)wcd_usbss_ctxt_, 21, &v7) )
                      goto LABEL_6;
                    if ( (v7 & 2) != 0 )
                    {
                      if ( (unsigned int)regmap_read(*(_QWORD *)wcd_usbss_ctxt_, 21, &v7) )
                        goto LABEL_6;
                      if ( (v7 & 2) != 0 )
                      {
                        if ( (unsigned int)regmap_read(*(_QWORD *)wcd_usbss_ctxt_, 21, &v7) )
                          goto LABEL_6;
                        if ( (v7 & 2) != 0 )
                        {
                          if ( (unsigned int)regmap_read(*(_QWORD *)wcd_usbss_ctxt_, 21, &v7) )
                            goto LABEL_6;
                          if ( (v7 & 2) != 0 )
                          {
                            if ( (unsigned int)regmap_read(*(_QWORD *)wcd_usbss_ctxt_, 21, &v7) )
                              goto LABEL_6;
                            if ( (v7 & 2) != 0 )
                            {
                              if ( (unsigned int)regmap_read(*(_QWORD *)wcd_usbss_ctxt_, 21, &v7) )
                                goto LABEL_6;
                              if ( (v7 & 2) != 0 )
                              {
                                dev_err(
                                  *(_QWORD *)(wcd_usbss_ctxt_ + 8),
                                  "%s: Surge check #2 failed\n",
                                  "wcd_usbss_is_in_reset_state");
                                goto LABEL_38;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            mutex_lock(wcd_usbss_ctxt_ + 408);
            v1 = wcd_usbss_ctxt_;
            if ( (*(_BYTE *)(wcd_usbss_ctxt_ + 401) & 1) == 0 )
            {
              updated = regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 5, 1, 0, 0, 0, 0);
              v5 = regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 5, 1, 1, 0, 0, 0) | updated;
              v6 = regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 5, 1, 0, 0, 0, 0);
              if ( v5 | v6 | (unsigned int)regmap_read(*(_QWORD *)wcd_usbss_ctxt_, 6, &v7) )
              {
                v1 = wcd_usbss_ctxt_;
              }
              else
              {
                v1 = wcd_usbss_ctxt_;
                if ( (v7 & 1) == 0 )
                {
                  dev_err(
                    *(_QWORD *)(wcd_usbss_ctxt_ + 8),
                    "%s: Surge check #3 failed\n",
                    "wcd_usbss_is_in_reset_state");
                  mutex_unlock(wcd_usbss_ctxt_ + 408);
                  goto LABEL_38;
                }
              }
            }
            mutex_unlock(v1 + 408);
          }
        }
      }
LABEL_6:
      release_runtime_env(wcd_usbss_ctxt_);
LABEL_7:
      v2 = msleep_interruptible(*(unsigned int *)(wcd_usbss_ctxt_ + 392));
    }
    while ( (kthread_should_stop(v2) & 1) == 0 );
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
