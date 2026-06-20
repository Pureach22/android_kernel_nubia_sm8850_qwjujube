__int64 __fastcall simple_amp_regulator_disable(__int64 a1)
{
  return regulator_bulk_disable(2, a1);
}
