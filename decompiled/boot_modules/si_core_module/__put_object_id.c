__int64 __fastcall _put_object_id(unsigned int a1)
{
  return xa_erase(&xa_si_objects, a1);
}
