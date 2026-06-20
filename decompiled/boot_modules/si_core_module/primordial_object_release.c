__int64 __fastcall primordial_object_release(__int64 a1)
{
  mutex_lock(&primordial_object_lock);
  if ( primordial_object == a1 )
    primordial_object = 0;
  return mutex_unlock(&primordial_object_lock);
}
