__int64 rmnet_shs_wake_ring()
{
  _pm_relax(qword_19480);
  rmnet_shs_wake = 1;
  return 0;
}
