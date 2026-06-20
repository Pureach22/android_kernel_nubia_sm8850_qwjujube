__int64 __fastcall nb7vpq904m_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  __int64 v3; // x0

  v1 = *(_QWORD *)(a1 + 184);
  result = usb_remove_redriver(v1);
  if ( !(_DWORD)result )
  {
    debugfs_remove(*(_QWORD *)(v1 + 248));
    v3 = *(_QWORD *)(v1 + 168);
    *(_BYTE *)(v1 + 208) = 0;
    destroy_workqueue(v3);
    result = *(_QWORD *)(v1 + 112);
    if ( result )
      return regulator_disable();
  }
  return result;
}
