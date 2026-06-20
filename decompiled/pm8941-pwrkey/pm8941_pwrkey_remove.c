__int64 __fastcall pm8941_pwrkey_remove(__int64 result)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(result + 168);
  if ( *(_BYTE *)(*(_QWORD *)(v1 + 96) + 8LL) == 1 )
    return unregister_reboot_notifier(v1 + 48);
  return result;
}
