unsigned __int64 __fastcall sde_dbg_init(__int64 a1)
{
  __int64 v2; // x0
  unsigned __int64 result; // x0

  if ( a1 )
  {
    v2 = _mutex_init(&unk_2942D0, "&sde_dbg_base.mutex", &sde_dbg_init___key);
    qword_2942A8 = (__int64)&qword_2942A8;
    qword_2942B0 = (__int64)&qword_2942A8;
    qword_2942C8 = a1;
    result = sde_evtlog_init(v2);
    sde_dbg_base = result;
    if ( result )
    {
      if ( result < 0xFFFFFFFFFFFFF001LL )
      {
        sde_dbg_base_evtlog = result;
        result = sde_reglog_init();
        qword_2942A0 = result;
        if ( result )
        {
          if ( result < 0xFFFFFFFFFFFFF001LL )
          {
            sde_dbg_base_reglog = result;
            qword_294358 = 0xFFFFFFFE00000LL;
            qword_294360 = (__int64)&qword_294360;
            qword_294368 = (__int64)&qword_294360;
            qword_294370 = (__int64)sde_dump_work;
            dword_294350 = 1;
            dword_29437C = 2;
            byte_294378 = 0;
            HIBYTE(word_294380) = 0;
            qword_294598 = 0xFFFFFF;
            qword_2945B0 = 0;
            qword_2945B8 = 0;
            qword_2945C0 = 0;
            qword_2945C8 = 0;
            qcom_va_md_register("display", &sde_md_notify_blk);
            printk(&unk_277861, "sde_dbg_init");
            return 0;
          }
        }
      }
    }
  }
  else
  {
    printk(&unk_2579ED, "sde_dbg_init");
    return 4294967274LL;
  }
  return result;
}
