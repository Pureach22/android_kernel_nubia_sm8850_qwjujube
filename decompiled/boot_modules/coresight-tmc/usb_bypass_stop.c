__int64 __fastcall usb_bypass_stop(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x1
  __int64 rwp_offset; // x0
  __int64 v4; // x8
  __int64 v5; // x1

  if ( result )
  {
    v1 = result;
    mutex_lock(result + 264);
    if ( *(_BYTE *)(v1 + 145) == 1 )
    {
      *(_BYTE *)(v1 + 145) = 0;
      _wake_up(v1 + 192, 3, 1, 0);
      printk(&unk_FCFC, v2);
      rwp_offset = tmc_get_rwp_offset(*(_QWORD *)(v1 + 368));
      v4 = *(_QWORD *)(v1 + 360);
      v5 = *(unsigned int *)(v1 + 392);
      *(_QWORD *)(v1 + 408) = rwp_offset;
      coresight_csr_set_byte_cntr(v4, v5, 0);
    }
    return mutex_unlock(v1 + 264);
  }
  return result;
}
