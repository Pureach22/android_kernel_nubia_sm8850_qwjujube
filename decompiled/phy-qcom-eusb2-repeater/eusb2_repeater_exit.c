__int64 __fastcall eusb2_repeater_exit(__int64 a1)
{
  return regulator_bulk_disable(
           *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 32LL) + 24LL),
           *(_QWORD *)(*(_QWORD *)(a1 + 152) + 24LL));
}
