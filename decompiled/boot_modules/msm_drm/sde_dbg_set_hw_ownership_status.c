__int64 __fastcall sde_dbg_set_hw_ownership_status(char a1)
{
  mutex_lock(&unk_2942D0);
  byte_2945DC = a1;
  return mutex_unlock(&unk_2942D0);
}
