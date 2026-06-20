__int64 __fastcall iommu_logger_unregister(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x9
  __int64 v5; // x0
  _QWORD *v6; // x24
  _QWORD *v7; // x21
  _QWORD *v8; // x8

  mutex_lock(&iommu_debug_attachments_lock);
  v4 = iommu_debug_attachments;
  if ( iommu_debug_attachments != (_UNKNOWN *)&iommu_debug_attachments )
  {
    do
    {
      v6 = (_QWORD *)*v4;
      v7 = v4 - 6;
      if ( v4[2] == a1 || *v7 == a2 )
      {
        v8 = (_QWORD *)v4[1];
        if ( (_QWORD *)*v8 == v4 && (_QWORD *)v6[1] == v4 )
        {
          v6[1] = v8;
          *v8 = v6;
        }
        else
        {
          _list_del_entry_valid_or_report(v4);
        }
        v5 = *(v4 - 4);
        *v4 = 0xDEAD000000000100LL;
        v4[1] = 0xDEAD000000000122LL;
        kfree(v5);
        kfree(v7);
      }
      v4 = v6;
    }
    while ( v6 != &iommu_debug_attachments );
  }
  return mutex_unlock(&iommu_debug_attachments_lock);
}
