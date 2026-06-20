__int64 sub_180DFC()
{
  __asm { LDTRSB          W10, [X11,#0xB9] }
  return _qdf_periodic_work_create();
}
