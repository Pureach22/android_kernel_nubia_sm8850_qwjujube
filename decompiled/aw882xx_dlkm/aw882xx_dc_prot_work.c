__int64 __fastcall aw882xx_dc_prot_work(__int64 a1)
{
  __int64 result; // x0

  result = aw882xx_dev_status(*(_QWORD *)(a1 - 224));
  if ( *(_BYTE *)(a1 - 303) && (_DWORD)result )
  {
    if ( (int)aw882xx_dev_dc_status(*(_QWORD *)(a1 - 224)) < 1 )
    {
      return queue_delayed_work_on(32, *(_QWORD *)(a1 - 216), a1, 250);
    }
    else
    {
      cancel_delayed_work_sync(a1 - 208);
      mutex_lock(a1 + 208);
      aw882xx_device_stop(*(_QWORD *)(a1 - 224));
      return mutex_unlock(a1 + 208);
    }
  }
  return result;
}
