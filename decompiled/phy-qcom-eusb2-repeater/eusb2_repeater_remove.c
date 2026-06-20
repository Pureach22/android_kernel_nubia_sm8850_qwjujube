__int64 __fastcall eusb2_repeater_remove(__int64 result)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(result + 168);
  if ( v1 )
    return regulator_bulk_disable(
             *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 152LL) + 32LL) + 24LL),
             *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 152LL) + 24LL));
  return result;
}
