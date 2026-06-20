void cdsprm_rpmsg_remove()
{
  void (__fastcall *v0)(__int64); // x8

  qword_A350 = 0;
  gcdsprm[0] = 0;
  if ( byte_A3D8 == 1 )
  {
    mutex_lock(&unk_A3A8);
    complete_all(&dword_A3F0);
    complete_all(&dword_A410);
    mutex_unlock(&unk_A3A8);
    v0 = (void (__fastcall *)(__int64))off_A4E0;
    qword_A4E8 = (__int64)off_A4E0;
    if ( (unsigned int)dword_A43C <= 7 )
    {
      if ( off_A4E0 )
      {
        if ( *((_DWORD *)off_A4E0 - 1) != 1995188558 )
          __break(0x8228u);
        v0(8);
      }
    }
  }
}
