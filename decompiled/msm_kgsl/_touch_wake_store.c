__int64 __fastcall touch_wake_store(__int64 a1, char a2)
{
  if ( (a2 & 1) != 0 )
    adreno_touch_wake(a1);
  return 0;
}
