__int64 __fastcall rproc_recovery_set(__int64 result)
{
  *(_BYTE *)(*(_QWORD *)(result + 40) + 785LL) = *(_BYTE *)(result + 1204);
  return result;
}
