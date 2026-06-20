__int64 __fastcall gsi_configure_regs(__int64 a1, unsigned int a2)
{
  __int64 result; // x0

  if ( gsi_ctx )
  {
    if ( *(_QWORD *)gsi_ctx )
    {
      if ( a2 - 14 <= 0xFFFFFFF2 )
      {
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d Incorrect version %d\n", "gsi_configure_regs", 4871, a2);
        return 0xFFFFFFFFLL;
      }
      else
      {
        gsihal_write_reg_nk(114, 0, 0);
        gsihal_write_reg_nk(115, 0, 0);
        gsihal_write_reg_nk(92, 0, 0);
        gsihal_write_reg_nk(93, 0, 0);
        gsihal_write_reg_nk(94, 0, 0);
        gsihal_write_reg_nk(95, 0, 0);
        gsihal_write_reg_nk(96, 0, 0);
        gsihal_write_reg_nk(97, 0, 0);
        gsihal_write_reg_nk(98, 0, 0);
        gsihal_write_reg_nk(99, 0, 0);
        gsihal_write_reg_nk(100, 0, 0);
        gsihal_write_reg_nk(101, 0, 0);
        gsihal_write_reg_nk(102, 0, 0);
        gsihal_write_reg_nk(103, 0, 0);
        gsihal_write_reg_nk(104, 0, 0);
        gsihal_write_reg_nk(105, 0, 0);
        gsihal_write_reg_nk(106, 0, 0);
        gsihal_write_reg_nk(107, 0, 0);
        gsihal_write_reg_nk(108, 0, 0);
        gsihal_write_reg_nk(109, 0, 0);
        gsihal_write_reg_nk(110, 0, 0);
        gsihal_write_reg_nk(111, 0, 0);
        gsihal_write_reg_nk(112, 0, 0);
        gsihal_write_reg_nk(113, 0, 0);
        gsihal_write_reg_nk(75, 0, 0);
        gsihal_write_reg_nk(76, 0, 0);
        gsihal_write_reg_nk(77, 0, 0);
        gsihal_write_reg_nk(78, 0, 0);
        gsihal_write_reg_nk(79, 0, 0);
        gsihal_write_reg_nk(80, 0, 0);
        gsihal_write_reg_nk(81, 0, 0);
        gsihal_write_reg_nk(82, 0, 0);
        gsihal_write_reg_nk(83, 0, 0);
        gsihal_write_reg_nk(84, 0, 0);
        gsihal_write_reg_nk(85, 0, 0);
        gsihal_write_reg_nk(86, 0, 0);
        gsihal_write_reg_nk(87, 0, 0);
        gsihal_write_reg_nk(88, 0, 0);
        gsihal_write_reg_nk(89, 0, 0);
        gsihal_write_reg_nk(90, 0, 0);
        result = 0;
        if ( a2 >= 6 )
        {
          gsihal_write_reg_nk(91, 0, 0);
          result = 0;
          if ( a2 >= 9 )
          {
            gsihal_write_reg_nk(123, 0, 0);
            result = 0;
            if ( a2 != 9 )
            {
              gsihal_write_reg_nk(124, 0, 0);
              return 0;
            }
          }
        }
      }
    }
    else
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d access to GSI HW has not been mapped\n", "gsi_configure_regs", 4866);
      return 4294967290LL;
    }
  }
  else
  {
    printk(&unk_2DEB9, "gsi_configure_regs", 4861);
    return 4294967288LL;
  }
  return result;
}
