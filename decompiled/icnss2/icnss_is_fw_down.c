__int64 icnss_is_fw_down()
{
  if ( !penv )
    return 0;
  if ( (*(_QWORD *)(penv + 1832) & 0x2000) != 0 || (*(_QWORD *)(penv + 1832) & 0x200) != 0 )
    return 1;
  return (*(_QWORD *)(penv + 1832) >> 15) & 1LL;
}
